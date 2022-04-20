#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
void dijkstra(vector<int> &dist, vector<vector<pii>> &graph, int src) {
  dist[src] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, src});
  while(!pq.empty()) {
    pii u = pq.top();
    pq.pop();
    if (dist[u.second] < u.first) continue;
    for(pii v: graph[u.second]) {
      if (dist[v.first] > dist[u.second] + v.second) {
        dist[v.first] = dist[u.second] + v.second;
        pq.push({dist[v.first], v.first});
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> dist(n + 1, vector<pii>());
  int s, e, w;
  for(int i=0; i<m; i++){
    cin >> s >> e >> w;
    dist[s].push_back({e, w});
    dist[e].push_back({s, w});
  }
  int m1, m2;
  cin >> m1 >> m2;
  vector<int> dist_1(n + 1, 30000000);
  vector<int> dist_n(n + 1, 30000000);
  vector<int> dist_btwn(n + 1, 30000000);
  dist_1[1] = 0;
  dist_n[n] = 0;
  dist_btwn[m1] = 0;
  dijkstra(dist_1, dist, 1);
  dijkstra(dist_n, dist, n);
  dijkstra(dist_btwn, dist, m1);
  int dist_1_m1 = dist_1[m1];
  int dist_1_m2 = dist_1[m2];
  int dist_n_m1 = dist_n[m1];
  int dist_n_m2 = dist_n[m2];
  int dist_btwn_m1 = dist_btwn[m2];
  if (dist_btwn_m1 == 30000000 || dist_1[n] == 30000000){
    cout << "-1\n"; return 0;
  }
  // 1->m1->m2->n or 1->m2->m1->n is the shortest
  int normies = min(dist_1_m1 + dist_n_m2, dist_1_m2 + dist_n_m1) + dist_btwn_m1;
  // 1->m1->m2->m1->n or 1->m2->m1->m2->n is the shortest (Since triangular inequality doesn't hold)
  int innormies = min(dist_1_m1 + dist_n_m1, dist_1_m2 + dist_n_m2) + 2 * dist_btwn_m1;
  cout << min(normies, innormies) << '\n';
  return 0;
}
