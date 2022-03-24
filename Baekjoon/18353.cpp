#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> val(n);
  for(auto &v: val)
    cin >> v;
  vector<int> dp(n);
  dp[0] = 1;
  int m = 1;
  for(int i=1; i<n; i++) {
    dp[i] = 1;
    for(int j=0; j<i; j++) {
      if(val[i] < val[j])
        dp[i] = max(dp[i], dp[j] + 1);
    }
    m = max(m, dp[i]);
  }
  cout << n - m << endl;
  return 0;
}
