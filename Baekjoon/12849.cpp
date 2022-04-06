#include<bits/stdc++.h>
using namespace std;

int main () {
  int adj[8][8] = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}};
  int D;
  cin >> D;
  vector<vector<int>> dp(2, vector<int>(8, 0));
  dp[0][0] = 1;
  for(int i=1; i<=D; i++) {
    for(int j=0; j<8; j++) {
      dp[i%2][j] = 0;
    }
    for(int j=0; j<8; j++) {
      for(int k=0; k<8; k++) {
        if(adj[j][k]) {
          dp[i%2][j] = (dp[(i+1)%2][k] + dp[i%2][j]) % 1000000007;
        }
      }
    }
  }
  cout << dp[D%2][0] << endl;
  return 0;
}
