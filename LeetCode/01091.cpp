class Solution {
public:
  int dir[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                   {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1)
      return -1;
    if (grid.size() == 1 && grid[0].size() == 1)
      return 1;
    vector<vector<int>> length(m, vector<int>(n));
    length[0][0] = 1;
    queue<pair<int, int>> on_path;
    on_path.push({0, 0});
    while (!on_path.empty()) {
      pair<int, int> curr = on_path.front();
      on_path.pop();
      for (int i = 0; i < 8; i++) {
        int nx = curr.first + dir[i][0];
        int ny = curr.second + dir[i][1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          continue;
        if (length[nx][ny] > 0)
          continue;
        if (grid[nx][ny] > 0)
          continue;
        if (nx == m - 1 && ny == n - 1)
          return length[curr.first][curr.second] + 1;
        length[nx][ny] = length[curr.first][curr.second] + 1;
        on_path.push({nx, ny});
      }
    }
    return -1;
  }
};
