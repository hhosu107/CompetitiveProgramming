#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  string x;
  cin >> x;
  vector<int> dp(n, 100000000);
  vector<string> prev(2);
  prev[0] = "BOJ";
  prev[1] = "JBO";
  dp[0] = 0;
  for(int i=1; i<n; i++) {
    int dp_chr = prev[0].find(x[i]);
    char curr_chr = prev[0][dp_chr];
    char prev_chr = prev[1][dp_chr];
    for(int j=0; j<i; j++) {
      if (x[j] == prev_chr) {
        dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
      }
    }
  }
  cout << (dp[n-1] == 100000000 ? -1 : dp[n-1]) << endl;
  return 0;
}
