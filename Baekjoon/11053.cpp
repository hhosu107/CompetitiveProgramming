#include<bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> a(n), dp(n);
  for(auto &i: a) cin >> i;
  dp[0] = 1;
  int m = 1;
  for(int i=1; i<n; i++) {
    dp[i] = 1;
    for(int j=0; j<i; j++) {
      if(a[j] < a[i]) dp[i] = max(dp[j] + 1, dp[i]);
    }
    m = max(m, dp[i]);
  }
  cout << m << endl;
  return 0;
}
