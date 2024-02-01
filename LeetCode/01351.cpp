class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int neg_count = 0;
    int row = 0, col = grid[0].size();
    while (col > 0 && row < grid.size()) {
      while (col > 0 && grid[row][col - 1] < 0)
        col--;
      neg_count += (grid[0].size() - col);
      row += 1;
    }
    if (row < grid.size())
      neg_count += (grid.size() - row) * grid[0].size();
    return neg_count;
  }
};
