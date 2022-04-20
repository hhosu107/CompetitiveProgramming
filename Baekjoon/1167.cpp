#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

/* From Dijkstra's theorem.
 * Choose an arbitrary vertex u and find the farthest vertex v from u.
 * Then find the farthest vertex w from u.
 * Tree's diameter is the distance between u and w.
 * https://drive.google.com/file/d/1zcGmL7ko3_GjQzA6f1Y6pCRPHrhMAtCB/view
 */

void bfs(int v, vector<int> &dist, const vector<vector<pii>> &edges) {
  queue<int> q;
  q.push(v);
  dist[v] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto &e : edges[u]) {
      int next = e.first, weight = e.second;
      if (dist[next] == -1) {
        dist[next] = dist[u] + weight;
        q.push(next);
      }
    }
  }
}

int main() {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<vector<pii>> edges(n+1);
  for(int i=0; i<n; i++) {
    int h;
    cin >> h;
    int hp, d;
    cin >> hp;
    while(hp != -1) {
      cin >> d;
      edges[h].push_back({hp, d});
      cin >> hp;
    }
  }
  vector<int> dist_from_1(n+1, -1);
  dist_from_1[1] = 0;
  bfs(1, dist_from_1, edges);
  int farthest_node_from_1 = 0;
  int farthest_distance_from_1 = 0;
  for(int i=2; i<=n; i++) {
    if (farthest_distance_from_1 < dist_from_1[i]) {
      farthest_node_from_1 = i;
      farthest_distance_from_1 = dist_from_1[i];
    }
  }
  vector<int> dist_from_farthest(n+1, -1);
  dist_from_farthest[farthest_node_from_1] = 0;
  bfs(farthest_node_from_1, dist_from_farthest, edges);
  int farthest_distance = 0;
  for(int i=1; i<=n; i++) {
    farthest_distance = max(farthest_distance, dist_from_farthest[i]);
  }
  cout << farthest_distance << '\n';
  return 0;
}
