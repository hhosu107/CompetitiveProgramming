#include<iostream>
#include<vector>
#include<array>
using namespace std;
array<int, 301> steps;
array<int, 301> dp;

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> steps[i+1];
  dp[1] = steps[1];
  dp[2] = dp[1] + steps[2];
  if (n <= 2) {
    cout << dp[n] << endl;
    return 0;
  }
  for(int i=3; i<=n; i++) {
    dp[i] = max(dp[i-3] + steps[i-1], dp[i-2]) + steps[i];
  }
  cout << dp[n] << endl;
  return 0;
}
