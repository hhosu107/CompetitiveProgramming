#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int bfs(int s, int e, vector<vector<int>> &con) {
  queue<pii> q;
  q.push({s, 0});
  bool found = false;
  vector<bool> visited(con.size(), false);
  while(!q.empty()) {
    pii cur = q.front();
    q.pop();
    visited[cur.first] = true;
    if (cur.first == e) return cur.second;
    for(auto n: con[cur.first]) {
      if (!visited[n]) {
        q.push({n, cur.second + 1});
      }
    }
  }
  return -1;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  int s, e;
  cin >> n >> s >> e;
  int rel;
  cin >> rel;
  vector<vector<int>> con(n + 1, vector<int>());
  for(int i=0; i<rel; i++) {
    pii edge;
    cin >> edge.first >> edge.second;
    con[edge.first].push_back(edge.second);
    con[edge.second].push_back(edge.first);
  }
  int dist = bfs(s, e, con);
  cout << dist << '\n';
  return 0;
}
