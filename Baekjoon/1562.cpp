#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>

using ll = long long;
using namespace std;
int main () {
  int n;
  cin >> n;
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(1024, vector<ll>(10, 0)));
  for(int i=0; i<10; i++)
    dp[0][1<<i][i] = 1;
  for(int i=1; i<n; i++) {
    for(int j=1; j<1024; j++) {
      for(int k=0; k<10; k++) {
        if (((j >> k) & 1) == 0) continue;
        if (k == 0) {
          dp[i][j][k] = (dp[i-1][j][1] + dp[i-1][j - (1 << k)][1]) % 1000000000;
        } else if (k == 9) {
          dp[i][j][k] = (dp[i-1][j][8] + dp[i-1][j - (1 << k)][8]) % 1000000000;
        } else {
          dp[i][j][k] = (((dp[i-1][j][k-1] + dp[i-1][j - (1 << k)][k-1]) % 1000000000) + ((dp[i-1][j][k+1] + dp[i-1][j - (1 << k)][k+1]) % 1000000000)) % 1000000000;
        }
      }
    }
  }
  ll sum = 0;
  for(int i=1; i<10; i++) {
    sum += dp[n-1][1023][i];
    sum %= 1000000000;
  }
  cout << sum << '\n';
  return 0;
}

