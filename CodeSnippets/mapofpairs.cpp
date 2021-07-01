#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

unordered_map<pair<int, int>, bool, hash_pair> um;
// Increase map speed
int main(){
    um.reserve(5);
}