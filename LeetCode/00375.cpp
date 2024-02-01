/* Sol) Some kind of dynamic programming method?
I want to compute the minimum cost of the range (x, y) by
computing min (z + max(cost(x, z-1), cost(z+1, y))), where z > x and z < y
Base cases: range (x, x) costs 0.
range (x, x+1) costs x.
Then (x, x+2) costs: x+1.
and so on...
Improvements: does efficient solution exist?
*/

class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n; i++) {
      dp[i][i + 1] = i;
    }
    for (int gap = 2; gap < n; gap++) {
      for (int i = 1; i <= n - gap; i++) {
        dp[i][i + gap] = 40000; // Maximum cost < 200 * 200
        for (int j = 1; j < gap; j++) {
          dp[i][i + gap] =
              min(dp[i][i + gap],
                  i + j + max(dp[i][i + j - 1], dp[i + j + 1][i + gap]));
        }
      }
    }
    return dp[1][n];
  }
};
