#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(3));
  for(auto &r: v)
    for(auto &c: r)
      cin >> c;
  vector<vector<int>> dp(n, vector<int>(3));
  dp[0] = v[0];
  for(int i=1; i<n; i++) {
    for(int j=0; j<3; j++) {
      dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + v[i][j];
    }
  }
  int m = min(dp[n-1][0], dp[n-1][1]);
  m = min(m, dp[n-1][2]);
  cout << m << endl;
  return 0;
}
