#include<bits/stdc++.h>
using namespace std;

int MAXI = 1000000007;
bool floyd_neg_cycle(vector<vector<int>> &graph) {
  vector<vector<int>> dist(graph.size(), vector<int>(graph.size(), MAXI));
  for(int i=0; i<graph.size(); i++) {
    for(int j=0; j<graph.size(); j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for(int k=0; k<graph.size(); k++) {
    for(int i=0; i<graph.size(); i++) {
      for(int j=0; j<graph.size(); j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        if (i == j && dist[i][j] < 0) {
          return true;
        }
      }
    }
  }
  for(int i=0; i<graph.size(); i++) {
    if(dist[i][i] < 0) {
      return true;
    }
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
    vector<vector<int>> graph(n, vector<int>(n, MAXI));
    int s, e, d;
    for(int i=0; i<m; i++) {
      cin >> s >> e >> d;
      graph[s-1][e-1] = d;
    }
    for(int i=0; i<w; i++) {
      cin >> s >> e >> d;
      graph[s-1][e-1] = -d;
    }
    bool nc = floyd_neg_cycle(graph);
    cout << (nc ? "YES" : "NO") << '\n';
  }
  return 0;
}
