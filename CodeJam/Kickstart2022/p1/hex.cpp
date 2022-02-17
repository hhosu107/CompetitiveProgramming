#include<bits/stdc++.h>

using namespace std;

/* Hex: N*N hexagon board. left/right side of the board: blue. Up/down side of
 * the board: red. 4 corners: both. If either one color has a connected path of
 * two sides, then that color wins and the game ends immediately.
 * With given game state, there are 4 possible cases: impossible (board cannot
 * be achieved from the initial state with the game rule: One drops their place
 * 2 or more times than the other / there can be two or more seperable connected
 * paths) / red wins / blue wins / nobody have not won yet.
 * Given game state, judge. */
/* Sol) How can we judge impossibility?
 * 1. Count each color plate. It it differs more than 1, impossible.
 * 2. If there are two or more separable connected paths, impossible. But how
 * can we seperate? Maybe I have to find a "cycle" in the given graph, where we
 * consider the up/down/left/right side of the board as a point.
 * Let's give an index for the left upper corner / upper side / right upper
 * corner / right side / right lower corner / lower side / left lower corner /
 * left side as 0~7. Then 0, 1, 2, 4, 5, 6 is colored as red, and 0, 2, 3, 4, 6,
 * 7 is colored as blue.
 * If there is a cycle which contains one of {0,1,2} and {4,5,6} or {2,3,4} and
 * {0,6,7}, it is impossible.
 * If it is not impossible, then we can judge the winner.
 * Red/Blue wins if there is a connected path which connects one of {0,1,2} and
 * {4,5,6} or one of {2,3,4} and {0,6,7}, respectively.
 * Nobody wins if there is no connected path.
 * Someone says try to flow. With unit weight, can it be connected with unit
 * flow? */
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> hscore(n, 0);
    int H = 0;
    int x;
    for(int i=0; i<n; i++) {
      cin >> x;
      if(minheap.empty()) {
        minheap.push(x);
        H = 1;
      } else if (x > H) {
        minheap.push(x);
        if (minheap.top() > H) {
          H++;
        } else {
          minheap.pop();
        }
      }
      hscore[i] = H;
    }
    cout << "Case #" << t << ": ";
    for(auto h: hscore) {
      cout << h << " ";
    }
    cout << '\n';
  }
  return 0;
}
