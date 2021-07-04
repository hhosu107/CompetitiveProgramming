#include<set>
#include<unordered_set>
/* template<class T, class Compare = less<T>, class Alloc = allocator<T>> class multiset
 * I.e., set.begin() returns the smallest one.
 * To sort, use other comparator.
 * .begin() : iterator to beginning; vice versa for .end().
 * .empty() (bool)
 * .size() : container size
 * .insert(el)
 * .erase(el): erase elements whose value is el
 * .erase(iterator): erase an element at the iterator
 * .swap(multiset instance): swap contents with given instance
 * .clear(): make empty
 * .find(el): find value and return the iterator.
 * .count(el): find number of values in the multiset.
 * .lower_bound(el): return the iterator s.t. the element before iterator is smaller than el.
 * .upper_bound(el): return the iterator that is the first element (or multiset.end()) that is larger than el.
 * Note: pq is much faster than multiset.
 */

/*
 * it has almost the same member functions, except bucket_count/max-bucket_count/bucket_size/bucket,
 * but they are not practical to use.
 */
