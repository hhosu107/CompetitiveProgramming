#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

using aii = array<array<int, 501>, 501>;

aii tri, dp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=n-i-1; j<n; j++) {
      cin >> tri[i][j];
    }
  }
  dp[0][n-1] = tri[0][n-1];
  for(int i=1; i<n; i++) {
    for(int j=n-i-1; j<n; j++) {
      dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + tri[i][j];
    }
  }
  int m = dp[n-1][0];
  for(int i=1; i<n; i++)
    m = max(dp[n-1][i], m);
  cout << m << '\n';
  return 0;
}
