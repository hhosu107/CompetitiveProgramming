#include<bits/stdc++.h>
using namespace std;
vector<int> board;
vector<bool> visited;
int t, n;
void input() {
  cin >> n;
  board = vector<int>(n);
  visited = vector<bool>(n);
  for (int &b: board) {
    cin >> b;
  }
}

int solve () {
  // save path; loop until one of already visited points is found.
  // if there is no point for that, there is no point to be added to a cycle.
  // if there is a point, it would be one of two cases:
  // 1) find a point that is not in a cycle:
  // a) if that point is also in the path we've currently walked, then this is a
  // cycle. Add that points.
  // b) if that point is not in the path we've currently walked, then previous
  // points are not in cycle.
  // 2) find a point that is already in a cycle: then previous points are not in
  // cycle.
  vector<int> path;
  int cnt = 0;
  for(int i=1; i<=n; i++) {
    path.clear();
    int j = i;
    while (!visited[j]) {
      visited[j] = true;
      path.emplace_back(j);
      j = board[j];
    }
    // If j was on the path, we get j, ..., path.end()-1 as a cycle.
    vector<int>::iterator it = find(path.begin(), path.end(), j);
    // If j was not on the path, we get j == path.end().
    // we add elements that are not in the cycle.
    // thus add distance between begin to j.
    cnt += distance(path.begin(), it);
  }
  return cnt;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> t;
  while(t--) {
    input();
    int res = solve();
    cout << res << '\n';
  }
  return 0;
}
