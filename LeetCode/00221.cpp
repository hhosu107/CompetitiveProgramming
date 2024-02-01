class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int rows = matrix.size(), cols = (rows > 0 ? matrix[0].size() : 0);
    vector<int> dp(cols + 1, 0);
    int max_square = 0, prev = 0;
    // Dp equation new_dp[i] = min(prev_dp[i-1], prev_dp[i], new_dp[i-1]) + 1.
    // prev means the previous row, new means the current row, so this dp
    // equation is identical to the 2D DP version.
    // Thus we store dp[i] in the temporary position before update it,
    // and update prev value as temp after updating dp[i].
    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        int temp = dp[j];
        if (matrix[i - 1][j - 1] == '1') {
          dp[j] = min({prev, dp[j - 1], dp[j]}) + 1;
          max_square = max(dp[j], max_square);
        }
      }
    }
    return max_square * max_square;
  }
};
