#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000
int adj[16][16];
int bit_dp[16][65536];

// Using dfs, select the next city to visit.
// On bit_dp, 1st index means the current city; 2nd index means cities that are
// already visited,
// which can be judged with (1 << i) & visited.
int n;
int max_vis;

int dfs(int city, int visited) {
  if(visited == max_vis) {
    return (adj[city][0] == 0 ? INF : adj[city][0]); // records distance from the last city to the started city.
  }
  if (bit_dp[city][visited] != -1) return bit_dp[city][visited];
  bit_dp[city][visited] = INF;
  for(int i=1; i<n; i++) {
    if (adj[city][i] == 0) continue;
    if (((1 << i) & visited) == (1 << i)) continue;
    bit_dp[city][visited] = min(bit_dp[city][visited], dfs(i, visited | (1 << i)) + adj[city][i]); // records remaining distance.
  }
  return bit_dp[city][visited];
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> adj[i][j];
  max_vis = (1 << n) - 1;
  memset(bit_dp, -1, sizeof(bit_dp));
  int min_tsp = dfs(0, 1);
  cout << min_tsp << '\n';
  return 0;
}
