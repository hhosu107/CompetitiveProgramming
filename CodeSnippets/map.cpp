#include<map>
#include<unordered_map>

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
