class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    const auto m = matrix.size();
    const auto n = matrix[0].size();
    // col0 plus matrix[0][1..n - 1] handle columns
    // matrix[0..m-1][0] handle rows
    int col0 = matrix[0][0];

    for (int r = 0; r < m; ++r) {
      // Handling column 0:
      if (matrix[r][0] == 0)
        col0 = 0;
      // We start from c = 1 to handle
      // rows 0 to m - 1 and columns 1 to n - 1
      for (int c = 1; c < n; ++c)
        if (matrix[r][c] == 0)
          matrix[r][0] = matrix[0][c] = 0;
    }
    for (int r = m - 1; r >= 0; --r) {
      // We handle c = 0 later
      for (int c = n - 1; c > 0; --c)
        if (matrix[r][0] == 0 || matrix[0][c] == 0)
          matrix[r][c] = 0;

      if (matrix[r][0] == 0 || col0 == 0)
        matrix[r][0] = 0;
    }
  }
};
