class Solution {
public:
  int dfs(vector<vector<int>> &grid, vector<bool> visited, int m, int n,
          vector<int> &dir_diff, int visited_cells, int valid_cells,
          int curr_cell, int endpoint) {
    if (curr_cell == endpoint) {
      if (visited_cells == valid_cells)
        return 1;
      return 0;
    }
    int ans = 0;
    for (int i = 0; i < dir_diff.size(); i++) {
      int new_cell = curr_cell + dir_diff[i];
      if (new_cell >= m * n || new_cell < 0 ||
          (n > 1 && ((dir_diff[i] > 0 && curr_cell % n == (n - 1) &&
                      new_cell % n == 0) ||
                     (dir_diff[i] < 0 && curr_cell % n == 0 &&
                      new_cell % n == (n - 1)))))
        continue;
      if (visited[new_cell])
        continue;
      if (grid[new_cell / n][new_cell % n] == -1)
        continue;
      visited[new_cell] = true;
      ans += dfs(grid, visited, m, n, dir_diff, visited_cells + 1, valid_cells,
                 new_cell, endpoint);
      visited[new_cell] = false;
    }
    return ans;
  }

  int uniquePathsIII(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<bool> visited(m * n, false);
    vector<int> dir_diff{1, -1, n, -n};
    int start_cell = -1;
    int endpoint = -1;
    int valid_cells = 0;
    for (int i = 0; i < m * n; i++) {
      if (grid[i / n][i % n] != -1)
        valid_cells += 1;
      if (grid[i / n][i % n] == 1) {
        start_cell = i;
        visited[i] = true;
      }
      if (grid[i / n][i % n] == 2)
        endpoint = i;
    }
    int ret = dfs(grid, visited, m, n, dir_diff, 1, valid_cells, start_cell,
                  endpoint);
    return ret;
  }
};
