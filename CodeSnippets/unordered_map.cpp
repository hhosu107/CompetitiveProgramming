#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<functional> // IMPORTANT! It enables to define hash<usertype> {}.
/* Unordered map / Unordered set 정의 시, key 값으로 struct나 class를 받게 될 경우,
 * 반드시 template<> struct hash<struct/class name> {
 * size_t operator()(struct/class const & s( const noexcept {
 * // calculate primitive member's hash and save them as size_t variable;
 * // combine them. For instance, h1 ^ (h2 << 1).
 * }
 * }
 * 를 짜야 한다.
 * 또한 bool operator==(const S& lhs, const S& rhs) {}를 짜야 한다. (hash
 * collision과는 별개).
 */
using std::string;
using std::size_t;
using std::hash;
struct S {
    string first_name;
    string last_name;
};
bool operator==(const S& lhs, const S& rhs) {
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}
 
// custom hash can be a standalone function object:
struct MyHash
{
    std::size_t operator()(S const& s) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(s.first_name);
        std::size_t h2 = std::hash<std::string>{}(s.last_name);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};
 
// custom specialization of std::hash can be injected in namespace std
template<>
struct std::hash<S>
{
    std::size_t operator()(S const& s) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(s.first_name);
        std::size_t h2 = std::hash<std::string>{}(s.last_name);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};
 
int main()
{
    std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    std::cout << "hash(" << std::quoted(str) << ") = " << str_hash << '\n';
 
    S obj = { "Hubert", "Farnsworth" };
    // using the standalone function object
    std::cout << "hash(" << std::quoted(obj.first_name) << ", "
              << std::quoted(obj.last_name) << ") = "
              << MyHash{}(obj) << " (using MyHash)\n" << std::setw(31) << "or "
              << std::hash<S>{}(obj) << " (using injected std::hash<S> specialization)\n";
 
    // custom hash makes it possible to use custom types in unordered containers
    // The example will use the injected std::hash<S> specialization above,
    // to use MyHash instead, pass it as a second template argument
    std::unordered_set<S> names = {obj, {"Bender", "Rodriguez"}, {"Turanga", "Leela"} };
    for(auto& s: names)
        std::cout << std::quoted(s.first_name) << ' ' << std::quoted(s.last_name) << '\n';
}
