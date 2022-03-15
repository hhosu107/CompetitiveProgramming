#include<bits/stdc++.h>
using namespace std;

int denom = 1000000000;
vector<vector<int>> dp;
int main () {
  int n;
  cin >> n;
  int pos[21] = {0};
  pos[0] = 1;
  for(int i=1; i<=20; i++) {
    pos[i] = pos[i-1] * 2;
  }
  dp = vector<vector<int>>(n + 1, vector<int>(21));
  dp[0][0] = 1;
  dp[1][0] = 1;
  for(int i=2; i<=n; i++) {
    for(int j=0; j<=20 && pos[j] <= i; j++) {
      for(int k=0; k<=j; k++) {
        dp[i][j] = (dp[i][j] + dp[i-pos[j]][k]) % denom;
      }
    }
  }
  int res = 0;
  for(int i=0; i<=20 && pos[i] <= n; i++) {
    res = (res + dp[n][i]) % denom;
  }
  cout << res << endl;
  return 0;
}
