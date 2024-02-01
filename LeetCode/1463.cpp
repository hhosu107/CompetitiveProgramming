// Think bottom-up DP first.
// DP state: requires to use row, col1, col2 where if robot1 located at (row,
// col1), robot2 located at (row, col2), estimates the maximum number of berries
// they will get until the last row.
// 1. Base: result += grid[row][col1] + grid[row][col2] if col1 != col2,
// grid[row][col1] o.w.
// 2. DP equation: max_(col1-1..col1+1,
// col2-1..col2+1)(dp[row+1][newcol1][newcol2]).
// 3. State compression: since the dp state depends on the previous (in this
// case, the next row) row, we alternate the row by dp[i%2]... and
// dp[(i+1)%2]...
// 4. What we have to calculate: dp[0][0][grid[0].size()-1] Since robot1 starts
// at 0, robot2 starts at grid[0].size()-1.

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int n = grid[0].size();
    int m = grid.size();
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n)));
    for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          int result = grid[i][j];
          if (j != k)
            result += grid[i][k];
          if (i != m - 1) {
            int max_val = 0;
            for (int col1 = j - 1; col1 <= j + 1; col1++) {
              for (int col2 = k - 1; col2 <= k + 1; col2++) {
                if (col1 >= 0 && col1 < n && col2 >= 0 && col2 < n) {
                  max_val = max(max_val, dp[(i + 1) % 2][col1][col2]);
                }
              }
            }
            result += max_val;
          }
          dp[i % 2][j][k] = result;
        }
      }
    }
    return dp[0][0][n - 1];
  }
};
