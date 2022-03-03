#include<bits/stdc++.h>
using namespace std;

int main () {
  string x, y;
  cin >> x >> y;
  int xl = x.length(), yl = y.length();
  vector<vector<int>> dp(xl + 1, vector<int>(yl + 1, 0));
  for(int i=1; i<=xl; i++) {
    for(int j=1; j<=yl; j++) {
      if (x[i-1] == y[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  cout << dp[xl][yl] << endl;
  return 0;
}
