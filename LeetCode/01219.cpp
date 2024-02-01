class Solution {
public:
  // When we go deep with recursion, save vector's size and reuse; do not call
  // it iteratively.
  int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x,
          int y, int m, int n, int collected) {
    /*
    if (x < m && x >= 0 && y < n && y >= 0 && grid[x][y] != 0 && !visited[x][y])
    { int res = 0; visited[x][y] = true; res = max({res, dfs(grid, visited, x +
    1, y, m, n, 0), dfs(grid, visited, x - 1, y, m, n, 0), dfs(grid, visited, x,
    y + 1, m, n, 0), dfs(grid, visited, x, y - 1, m, n, 0)}); visited[x][y] =
    false; return grid[x][y] + res;
    }
    return 0;
    */

    // Tail recursion is faster.
    int max_val = collected;
    for (int i = 0; i < 4; i++) {
      int nx = x + dd[i][0];
      int ny = y + dd[i][1];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        continue;
      } else if (grid[nx][ny] == 0 || visited[nx][ny] == true) {
        continue;
      }
      visited[nx][ny] = true;
      int deeper_val =
          dfs(grid, visited, nx, ny, m, n, collected + grid[nx][ny]);
      visited[nx][ny] = false;
      max_val = max(max_val, deeper_val);
    }
    return max_val;
  }
  int getMaximumGold(vector<vector<int>> &grid) {
    int max_val = 0;
    vector<vector<bool>> visited(grid.size(),
                                 vector<bool>(grid[0].size(), false));
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0)
          continue;
        int edge_cnt = 0;
        for (int k = 0; k < 4; k++) {
          int nx = i + dd[k][0];
          int ny = j + dd[k][1];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
          else if (grid[nx][ny] == 0)
            continue;
          edge_cnt += 1;
        }
        if (edge_cnt >= 3)
          continue;
        visited[i][j] = true;
        max_val = max(max_val, dfs(grid, visited, i, j, m, n, grid[i][j]));
        visited[i][j] = false;
      }
    }
    return max_val;
  }
};
