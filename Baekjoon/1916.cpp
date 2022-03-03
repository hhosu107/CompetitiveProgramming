#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ppi = pair<int, pii>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  map<int, set<pii>> edges;
  int w, s, e;
  for(int i=0; i<m; i++){
    cin >> s >> e >> w;
    if (edges.find(s) == edges.end()) {
      edges[s] = set<pii>();
    }
    edges[s].insert({e, w});
  }
  int start, end;
  cin >> start >> end;
  vector<int> dist(n + 1, INT_MAX);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist[start] = 0;
  pq.push({0, start});
  while(!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for(auto it = edges[u].begin(); it != edges[u].end(); ++it) {
      int v = it->first;
      int weight = it->second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }
  cout << dist[end] << '\n';
  return 0;
}
