#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  vector<int> dp(n, 0);
  dp[0] = a[0];
  dp[1] = dp[0] + a[1];
  dp[2] = max(dp[0] + a[2], a[1] + a[2]);
  for(int i=2; i<n; i++)
    dp[i] = max(dp[i-1], max(dp[i-2] + a[i], dp[i-3] + a[i] + a[i-1]));
  cout << dp[n-1] << endl;
  return 0;
}
