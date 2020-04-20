#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/* C. Card: rank 1~R, suit 1~S, each (rank, suit) card exists exactly once. Denote (r, s)
 * Sorted from top to bottom by suit in increasing order, with ties being broken by ranks in increasing order.
 * i.e., (1, 1), (2, 1), ..., (R, 1), (1, 2), ...
 * Want to reorder by rank, but doesn't care about the order of suits. i.e., (1, something), ..., (1, something), (2, .), ...
 * ... using only the following 3-part operation.
 * 1. Take 1~k cards from the top of the deck, and set that selection aside as pile A.
 * 2. Take 1~k cards from the new top of the deck, and set that selection aside as pile B.
 * 3. Finally put pile A on top of the deck and the put pile B on top of the new deck.
 * (THAT IS THE SHUFFLE on the general poker, you know. pick intermediate part from the deck and move that to the top.)
 * Given R/S, find a sequence of operations that reorders the deck with minimum possible number of operations.
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    cout << "Case #" << t << ": ";
  }
  return 0;
}
