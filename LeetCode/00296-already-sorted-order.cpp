class Solution {
public:
  vector<int> collectRows(vector<vector<int>> &grid) {
    vector<int> rows;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          rows.push_back(i);
        }
      }
    }
    return rows;
  }
  vector<int> collectCols(vector<vector<int>> &grid) {
    vector<int> cols;
    for (int i = 0; i < grid[0].size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        if (grid[j][i] == 1) {
          cols.push_back(i);
        }
      }
    }
    return cols;
  }
  int minDistance1D(vector<int> &points, int center) {
    int distance = 0;
    for (int point : points)
      distance += abs(point - center);
    return distance;
  }
  int minTotalDistance(vector<vector<int>> &grid) {
    vector<int> rows = collectRows(grid);
    vector<int> cols = collectCols(grid);
    int row = rows[rows.size() / 2];
    int col = cols[cols.size() / 2];
    return minDistance1D(rows, row) + minDistance1D(cols, col);
  }
};
