#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main () {
  int n;
  cin >> n;
  vector<pii> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  vector<int> dp(n, 1);
  int max_ans = 0;
  for(int i=1; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(a[i].second > a[j].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    max_ans = max(max_ans, dp[i]);
  }
  cout << n - max_ans << endl;
  return 0;
}
