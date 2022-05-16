#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> num(n);
  for(auto& x: num) cin >> x;
  vector<int> dp(n);
  dp[0] = 1;
  int max_num = 1;
  for(int i=1; i<n; i++) {
    dp[i] = 1;
    for(int j=0; j<i; j++) {
      if (num[i] > num[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
    max_num = max(max_num, dp[i]);
  }
  cout << max_num << endl;
  return 0;
}
