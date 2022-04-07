#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

bool bfs(vector<pii> &pts) {
  vector<bool> visited(pts.size(), false);
  queue<ppi> q;
  q.push({pts[0], 0});
  while(!q.empty()) {
    ppi cur = q.front();
    q.pop();
    if (cur.second == pts.size() - 1) return true;
    if(visited[cur.second]) continue;
    visited[cur.second] = true;
    for(int i=0; i<pts.size(); i++) {
      if (i == cur.second) continue;
      if (visited[i]) continue;
      if (abs(pts[i].first - cur.first.first) + abs(pts[i].second - cur.first.second) <= 1000) {
        q.push({pts[i], i});
      }
    }
  }
  return false;
}

using pii = pair<int, int>;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<pii> c(n + 2);
    for (auto &x: c)
      cin >> x.first >> x.second;
    bool ans = bfs(c);
    cout << (ans ? "happy" : "sad") << '\n';
  }
  return 0;
}
