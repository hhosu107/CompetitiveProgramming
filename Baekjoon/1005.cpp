#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
int main () {
  int T;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    vector<ll> cost(n);
    for(int i=0; i<n; i++) {
      cin >> cost[i];
    }
    vector<vector<int>> edges(n, vector<int>());
    vector<int> in_edges(n, 0);
    int s, e;
    for(int i=0; i<k; i++) {
      cin >> s >> e;
      s--; e--;
      edges[s].push_back(e);
      in_edges[e]++;
    }
    int w;
    cin >> w;
    w--;
    vector<ll> dp(n, 0LL);
    queue<int> topological;
    for(int i=0; i<n; i++){
      if (in_edges[i] == 0) {
        topological.push(i);
        dp[i] = cost[i];
      }
    }
    while(!topological.empty()) {
      int cur = topological.front();
      topological.pop();
      for(int next: edges[cur]) {
        in_edges[next]--;
        dp[next] = max(dp[next], dp[cur] + cost[next]);
        if (in_edges[next] == 0) {
          topological.push(next);
        }
      }
    }
    cout << dp[w] << '\n';
  }
  return 0;
}
