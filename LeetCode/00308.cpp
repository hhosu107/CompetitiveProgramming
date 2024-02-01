class NumMatrix {
public:
  int rows;
  int cols;
  vector<vector<int>> nums;
  vector<vector<int>> modifiers;
  void update_x(int x, int y, int val) {
    while (x < rows) {
      update_y(x, y, val);
      x += (x & -x);
    }
  }

  void update_y(int x, int y, int val) {
    while (y < cols) {
      modifiers[x][y] += val;
      y += (y & -y);
    }
  }
  int sum_from_origin(int x, int y) {
    int row_sum = 0;
    while (x > 0) {
      row_sum += sum_from_origin_y(x, y);
      x -= (x & -x);
    }
    return row_sum;
  }
  int sum_from_origin_y(int x, int y) {
    int col_sum = 0;
    while (y > 0) {
      col_sum += modifiers[x][y];
      y -= (y & -y);
    }
    return col_sum;
  }
  NumMatrix(vector<vector<int>> &matrix) {
    nums = matrix;
    rows = matrix.size() + 1;
    cols = matrix[0].size() + 1;
    modifiers = vector<vector<int>>(rows, vector<int>(cols, 0));
    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        update_x(i, j, matrix[i - 1][j - 1]);
      }
    }
  }

  void update(int row, int col, int val) {
    update_x(row + 1, col + 1, val - nums[row][col]);
    nums[row][col] = val;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int partial_sums =
        sum_from_origin(row2 + 1, col2 + 1) - sum_from_origin(row1, col2 + 1) -
        sum_from_origin(row2 + 1, col1) + sum_from_origin(row1, col1);
    return partial_sums;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
