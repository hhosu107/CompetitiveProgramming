#include<algorith>

/*
 * for_each(container::iterator first, container::iterator second, unary_fn) is in algorithm
 * copy(sourceVector.begin(), sourceVector.end(), destVector.begin()). In general replaced with starting-position, next to ending position, and starting position of the destination.
 * assign: destVector.assign(sourceVector.begin(), sourceVector.end()).
 * set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::inserter(diff, diff.begin())).
 * Note: v1/v2 must be sorted, i.e., it would be a sorted vector or just a multiset.
 * ex) {1, 2, 5, 5, 5, 9} \\ {2, 5, 7} = {1, 5, 5, 9}.
 * next_permutation(s.begin(), s.end()): Suppose that s = {s0, s1, ..., sn-1}. Then it finds the next permutation and manipulates s in that order.
 * ex) s = [1, 2, 3]. next_permutation(s.begin(), s.end()) = [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1], ...
 * Then it outputs false if there is no other permutation.
 * max(initialize_list, comparator (bool operator(obj i1, obj i2) { return i1.something < i2.something }) / min.
 */
