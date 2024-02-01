class Solution {
public:
  // Dp state: dp[i+1][j+1] 값을 보고, row_consecutive1[i][j] 및
  // col_consecutive1[i][j]값을 참조하여 dp[i][j] 값을 결정한다. 즉 i, j를 왼쪽
  // 위 꼭지점으로 하는 가장 큰 matrix size 구해서 넣기. Too complex.
  int maximalSquare(vector<vector<char>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> row_consec(n, vector<int>(m, 0));
    vector<vector<int>> col_consec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      int consec_score = 0;
      int consec_idx = 0;
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          if (consec_score == 0)
            consec_idx = j;
          consec_score += 1;
        } else if (consec_score > 0) {
          for (int k = consec_idx; k < j; k++) {
            row_consec[i][k] = consec_score;
            consec_score--;
          }
        }
      }
      if (consec_score > 0) {
        for (int k = consec_idx; k < m; k++) {
          row_consec[i][k] = consec_score;
          consec_score--;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int consec_score = 0;
      int consec_idx = 0;
      for (int j = 0; j < n; j++) {
        if (matrix[j][i] == '1') {
          if (consec_score == 0)
            consec_idx = j;
          consec_score += 1;
        } else if (consec_score > 0) {
          for (int k = consec_idx; k < j; k++) {
            col_consec[k][i] = consec_score;
            consec_score--;
          }
        }
      }
      if (consec_score > 0) {
        for (int k = consec_idx; k < n; k++) {
          col_consec[k][i] = consec_score;
          consec_score--;
        }
      }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    int max_size = 0;
    for (int i = 0; i < m; i++) {
      if (row_consec[n - 1][i]) {
        dp[n - 1][i] = 1;
        max_size = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (col_consec[i][m - 1]) {
        dp[i][m - 1] = 1;
        max_size = 1;
      }
    }
    for (int k = 1; k <= min(n - 1, m - 1); k++) {
      // Starting from (n-k-1, m-k-1)
      for (int i = m - k - 1; i >= 0; i--) {
        dp[n - k - 1][i] =
            min({col_consec[n - k - 1][i], row_consec[n - k - 1][i],
                 dp[n - k][i + 1] + 1});
        max_size = max(max_size, dp[n - k - 1][i]);
        // Dp equation: if matrix[n-k-1][i] == '1',
        // min(min(col_consec[n-k-1][i], row_consec[n-k-1][i]), dp[n-k][i+1] +
        // 1)
      }
      for (int i = n - k - 1; i >= 0; i--) {
        dp[i][m - k - 1] =
            min({col_consec[i][m - k - 1], row_consec[i][m - k - 1],
                 dp[i + 1][m - k] + 1});
        max_size = max(max_size, dp[i][m - k - 1]);
      }
    }
    return max_size * max_size;
  }
};
