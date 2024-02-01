class Solution {
public:
  bool bfs(vector<vector<int>> &grid, int M) {
    int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    using pii = pair<int, int>;
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty()) {
      pii head = q.front();
      q.pop();
      if (head.first == R - 1 && head.second == C - 1) {
        return true;
      }
      for (int i = 0; i < 4; i++) {
        int nx = head.first + dd[i][0];
        int ny = head.second + dd[i][1];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
          continue;
        }
        if (visited[nx][ny]) {
          continue;
        }
        if (abs(grid[head.first][head.second] - grid[nx][ny]) > M) {
          continue;
        }
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
    return false;
  }
  int bin_search(vector<vector<int>> &grid, int l, int h) {
    if (l + 1 >= h) {
      bool possible = bfs(grid, l);
      if (possible)
        return l;
      else
        return l + 1;
    }
    int mid = (l + h) / 2;
    bool possible = bfs(grid, mid);
    if (possible) {
      int smaller = bin_search(grid, l, mid);
      return smaller;
    } else {
      int larger = bin_search(grid, mid + 1, h);
      return larger;
    }
  }

  int minimumEffortPath(vector<vector<int>> &heights) {
    int min_height = bin_search(heights, 0, 100000000);
    return min_height;
  }
};
