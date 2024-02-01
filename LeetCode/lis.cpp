#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int> &x) {
  int n = x.size();
  vector<int> dp(n, 1);
  int maxInc = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (x[i] > x[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    maxInc = max(maxInc, dp[i]);
  }
  return maxInc;
}

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  cout << longestIncreasingSubsequence(x) << endl;
  return 0;
}
