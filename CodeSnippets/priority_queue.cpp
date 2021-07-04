#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

//max heap
priority_queue <int> g = priority_queue<int>();
//min heap
priority_queue <int, vector<int>, greater<int>> gquiz;

// Priority queue recognizes the overload of < operator. > Doesn't.
// If < actually judges a < b, then it changes to maxheap.
// O.W., if < judges a > b, then it is minheap.
//
// The container shall be accessible from random access iterators and support empty(), size9), front(), push_back(), pop_back().

/* PQ member functions:
 * void .empty()
 * int .size()
 * type .top()
 * void .push(elmt)
 * void .pop()
 * .emplace(elmt constructor)
 * .swap()
 */
