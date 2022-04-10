#include<bits/stdc++.h>
using namespace std;

/* Floyd.
 * https://ko.wikipedia.org/wiki/%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C-%EC%9B%8C%EC%85%9C_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
 * https://www.acmicpc.net/problem/11404
 * shortest_path(i, j, k) : shortest path from i to j where intermediate nodes
 * are only [1, ..., k].
 * shortest_path(i, j, 0) = w[i, j]; // No intermediate nodes are needed.
 * shortest_path(i, j, k) = min(shortest_path(i, j, k-1), shortest_path(i, k, k-1) + shortest_path(k, j, k-1));
 */
using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  ll s, e, c;
  vector<vector<ll>> routes(n + 1, vector<ll>(n + 1, 100000000));
  for(int i=0; i<m; i++) {
    cin >> s >> e >> c;
    routes[s][e] = min(routes[s][e], c);
  }
  for(int i=0; i<=n; i++)
    routes[i][i] = 0;
  for(int k=1; k<=n; k++) {
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        if(routes[i][j] > routes[i][k] + routes[k][j])
          routes[i][j] = routes[i][k] + routes[k][j];
      }
    }
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(routes[i][j] == 100000000)
        routes[i][j] = 0;
      cout << routes[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
