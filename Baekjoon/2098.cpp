#include<iostream>
#include<algorithm>
using namespace std;

#define INF 1000000000
int adj[16][16];
int bit_dp[16][65536];

// Using dfs, select the next city to visit.
// On bit_dp, 1st index means the current city; 2nd index means cities that are
// already visited,
// which can be judged with (1 << i) & visited.
int n;

int dfs(int city, int visited) {
  int i;
  if(visited == (1 << n) - 1) {
    return (adj[city][0] == 0 ? INF : adj[city][0]); // records distance from the last city to the started city.
  }
  if (bit_dp[city][visited] != INF) return bit_dp[city][visited];
  for(int i=0; i<n; i++) {
    int next_city = (1 << i);
    if (!(next_city & visited) && adj[city][i]) {
      int next_visited = (visited | next_city);
      int rem_dist = dfs(i, next_visited);
      bit_dp[city][visited] = min(bit_dp[city][visited], rem_dist + adj[city][i]); // records remaining distance.
    }
  }
  return bit_dp[city][visited];
}

void cleanup () {
  for(int i=0; i<n; i++) {
    for(int j=0; j<(1 << n); j++)
      bit_dp[i][j] = INF;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> adj[i][j];
  cleanup();
  int min_tsp = dfs(0, 1);
  cout << min_tsp << '\n';
  return 0;
}
