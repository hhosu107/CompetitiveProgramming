#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ppi = pair<int, pii>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, party;
  cin >> n >> m >> party;
  map<int, set<pii>> edges;
  map<int, set<pii>> rev_edges;
  int w, s, e;
  for(int i=0; i<m; i++){
    cin >> s >> e >> w;
    if (edges.find(s) == edges.end()) {
      edges[s] = set<pii>();
    }
    edges[s].insert({e, w});
    if (rev_edges.find(e) == edges.end()) {
      rev_edges[e] = set<pii>();
    } rev_edges[e].insert({s, w});
  }
  vector<int> party_to_dist(n + 1, INT_MAX / 2);
  vector<int> dist_to_party(n + 1, INT_MAX / 2);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  party_to_dist[party] = 0;
  pq.push({0, party});
  while(!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for(auto it = edges[u].begin(); it != edges[u].end(); ++it) {
      int v = it->first;
      int weight = it->second;
      if (party_to_dist[v] > party_to_dist[u] + weight) {
        party_to_dist[v] = party_to_dist[u] + weight;
        pq.push({party_to_dist[v], v});
      }
    }
  }
  dist_to_party[party] = 0;
  pq.push({0, party});
  while(!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for(auto it = rev_edges[u].begin(); it != rev_edges[u].end(); ++it) {
      int v = it->first;
      int weight = it->second;
      if (dist_to_party[v] > dist_to_party[u] + weight) {
        dist_to_party[v] = dist_to_party[u] + weight;
        pq.push({dist_to_party[v], v});
      }
    }
  }
  int dist_max = -1;
  for(int i=1; i<=n; i++) {
    if (party_to_dist[i] != INT_MAX / 2 && dist_to_party[i] != INT_MAX / 2 && party_to_dist[i] + dist_to_party[i] > dist_max) {
      dist_max = party_to_dist[i] + dist_to_party[i];
    }
  }
  cout << dist_max << '\n';
  return 0;
}
