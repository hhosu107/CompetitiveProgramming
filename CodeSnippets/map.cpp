#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
/* template<class key, class T, class Hash=hash<key>, class Pred=equal_to<key>, class Alloc = allocator<pair<>const key, T> > > class unordered_multimap; */

/* For almost all of the case, we just use
 * unordered_map<Key, T> type.
 * .empty(), .size(), .insert(el), .erase(el), .clear(), .swap(unordered_map instance),
 * .find(el) -> iterator to the element.
 * .equal_range(el) -> range of elements
pair<iterator,iterator>
   equal_range ( const key_type& k );
pair<const_iterator,const_iterator>
   equal_range ( const key_type& k ) const;
for_each(InputIterator first, InputIterator last, function fn): from first (inclusive) to last (exclusive), do fn.
In this case, for(unordered_map<key, T>::iterator x = range.first; x != range.second; x++) works.
* Rather than using .find() != .end(), use .count(). It performs null search if
* .count() == 0.
*/
/* Ex) hash table with collision as vector */
template<typename K, typename V>
class HashMapList {
  private:
    map<K, vector<V>> hash_table = map<K, vector<V>>();
  public:
    void put (K key, V item) {
      if (hash_table.find(key) == hash_table.end()) {
        hash_table[key] = vector<V>();
      }
      hash_table[key].push_back(item);
    }
    vector<V> get(K key) {
      return hash_table[key];
    }
    bool containsKey(K key) {
      return hash_table.find(key) != hash_table.end();
    }
    bool containsKeyValue(K key, V value) {
      vector<V> key_list = get(key);
      if (key_list.size() == 0) return false;
      return find(key_list.begin(), key_list.end(), value) != key_list.end();
    }
    set<K> keySet() {
      set<K> return_keys;
      for (auto const& [k, v]: hash_table) {
        return_keys.insert(k);
      }
      return return_keys;
    }
};

int main () {
  HashMapList<int, string> hash_table;
  hash_table.put(0, "str");
  hash_table.put(0, "strp");
  hash_table.put(1, "strps");
  cout << hash_table.containsKey(2) << endl;
  cout << hash_table.containsKey(1) << endl;
  for (int k: hash_table.keySet()) {
    cout << k << endl;
  }
  cout << hash_table.containsKeyValue(0, "strp") << endl;
  cout << hash_table.containsKeyValue(0, "strps") << endl;

  return 0;
}
