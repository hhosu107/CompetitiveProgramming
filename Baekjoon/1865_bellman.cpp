#include<bits/stdc++.h>
using namespace std;

int MAXI = 1000000007;
using pii = pair<int, int>;
bool belmann_neg_cycle(vector<vector<pii>> &graph) {
  vector<int> dist(graph.size(), MAXI);
  dist[0] = 0;

  for(int i=1; i<graph.size(); i++) {
    for(int j=0; j<graph.size(); j++)
      for(auto &e: graph[j]) {
        if (dist[e.first] > dist[j] + e.second)
          dist[e.first] = dist[j] + e.second;
    }
  }

  for(int i=0; i<graph.size(); i++) {
    for(auto &e: graph[i])
      if(dist[e.first] > dist[i] + e.second)
        return true;
  }
  return false;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<pii>> graph(n, vector<pii>());
    int s, e, d;
    for(int i=0; i<m; i++) {
      cin >> s >> e >> d;
      graph[s-1].push_back({e-1, d});
      graph[e-1].push_back({s-1, d});
    }
    for(int i=0; i<w; i++) {
      cin >> s >> e >> d;
      graph[s-1].push_back({e-1, -d});
    }
    bool nc = belmann_neg_cycle(graph);
    cout << (nc ? "YES" : "NO") << '\n';
  }
  return 0;
}
