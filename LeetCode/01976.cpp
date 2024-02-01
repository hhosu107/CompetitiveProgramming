#include <bits/stdc++.h>
using namespace std;

/* Count number of fastest paths from source to destination.
 * Idea: If we find a shorter path (s...i-d), update count[d] = count[i].
 * If we find a path with the same length (s...i-d), update count[d] + count[i].
 * finally return count[D].
 * Leetcode 1976.
 * Reference: https://www.baeldung.com/cs/graph-number-of-shortest-paths
 */
using pii = pair<int, int>;
;
using ll = long long;
int countPaths(int n, vector<vector<int>> &roads) {
  int s = 0, D = n - 1;
  map<int, vector<pii>> adj;
  for (auto road : roads) {
    if (adj.find(road[0]) == adj.end())
      adj[road[0]] = vector<pii>();
    if (adj.find(road[1]) == adj.end())
      adj[road[1]] = vector<pii>();
    adj[road[0]].push_back({road[1], road[2]});
    adj[road[1]].push_back({road[0], road[2]});
  }
  vector<int> distance(n, INT_MAX);
  vector<ll> paths(n, 0);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  distance[s] = 0;
  paths[s] = 1;
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (adj.find(u) == adj.end())
      continue;
    for (auto [v, w] : adj[u]) {
      if (distance[v] > d + w) {
        pq.push({d + w, v});
        distance[v] = d + w;
        paths[v] = paths[u];
      } else if (distance[v] == d + w) {
        paths[v] = (paths[v] + paths[u]) % 1000000007;
      }
    }
  }
  return paths[D];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> roads(m, vector<int>(3));
  for (auto &road : roads)
    cin >> road[0] >> road[1] >> road[2];
  int num_paths = countPaths(n, roads);
  cout << num_paths << '\n';
  return 0;
}
