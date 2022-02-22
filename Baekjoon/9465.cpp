#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* when a[i][j] is picked, a[i+dx][j+dy] cannot be picked.
 * a = [2 * n].
 * sol) dp[i][j] = max(dp[(i+1)%2][j-1], dp[0][j-2], dp[1][j-2]) + a[i][j].
 * max(dp[0][n-1], dp[1][n-1]). */

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T-- > 0) {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for(auto &i: a)
      for(auto &j: i)
        cin >> j;
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];
    dp[0][1] = dp[1][0] + a[0][1];
    dp[1][1] = dp[0][0] + a[1][1];
    for(int i=2; i<n; i++) {
      dp[0][i] = max(max(dp[0][i-2], dp[1][i-2]), dp[1][i-1]) + a[0][i];
      dp[1][i] = max(max(dp[0][i-2], dp[1][i-2]), dp[0][i-1]) + a[1][i];
    }
    cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
  }
  return 0;
}
