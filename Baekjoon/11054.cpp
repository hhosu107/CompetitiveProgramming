/* 11054: bitonic sequence
 * Sol): LIS from begin & LIS from rbegin. Sum both. */
#include<bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n), dp(n), rdp(n);
  for(auto &i: a) cin >> i;
  dp[0] = 1;
  rdp[n-1] = 1;
  for(int i=1; i<n; i++) {
    dp[i] = 1;
    rdp[n-1-i] = 1;
    for(int j=0; j<i; j++) {
      if(a[j] < a[i]) dp[i] = max(dp[j] + 1, dp[i]);
      if(a[n-1-j] < a[n-1-i]) rdp[n-1-i] = max(rdp[n-1-j] + 1, rdp[n-1-i]);
    }
  }
  int maxi = 0;
  for(int i=0; i<n; i++) {
    maxi = max(maxi, dp[i] + rdp[i] - 1);
  }
  cout << maxi << endl;
  return 0;
}
