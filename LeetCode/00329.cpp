class Solution {
public:
  int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int m, n;
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size();
    n = matrix[0].size();
    int ans = 0;
    vector<vector<int>> cache(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans = max(ans, dfs(matrix, i, j, cache));
      }
    }
    return ans;
  }
  int dfs(vector<vector<int>> &matrix, int i, int j,
          vector<vector<int>> &cache) {
    if (cache[i][j] != 0)
      return cache[i][j];
    for (int d = 0; d < 4; d++) {
      int x = i + dirs[d][0];
      int y = j + dirs[d][1];
      if (x < 0 || x >= m || y < 0 || y >= n)
        continue;
      if (matrix[x][y] <= matrix[i][j])
        continue;
      cache[i][j] = max(cache[i][j], dfs(matrix, x, y, cache));
    }
    cache[i][j] += 1;
    return cache[i][j];
  }
};
