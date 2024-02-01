struct PointScore {
  int x;
  int y;
  int score;
  PointScore() : x(0), y(0), score(0) {}
  PointScore(int _x, int _y, int _score) : x(_x), y(_y), score(_score) {}
};

class Solution {
public:
  int maximumMinimumPath(vector<vector<int>> &grid) {
    int row = grid.size(), col = grid[0].size();
    using pii = pair<int, int>;
    auto comp = [](const PointScore &l, const PointScore &r) {
      return l.score < r.score;
    };
    priority_queue<PointScore, vector<PointScore>, decltype(comp)> pq(comp);
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited(row, vector<bool>(col));
    int score = 2147483647;
    pq.push({0, 0, grid[0][0]});
    while (!pq.empty()) {
      PointScore p = pq.top();
      pq.pop();
      visited[p.x][p.y] = true; // Since we are using priority queue, if a cell
                                // is checked in priority queue, then this cell
                                // already has its maximum possible score.
      score = min(score, grid[p.x][p.y]); // Path score update
      if (p.x == row - 1 && p.y == col - 1)
        break;
      for (int i = 0; i < 4; i++) {
        int nx = p.x + dir[i][0];
        int ny = p.y + dir[i][1];
        if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny]) {
          pq.push({nx, ny, grid[nx][ny]});
        }
      }
    }
    return score;

    // If 2 directional version:
    /*
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n); // For each step i, dp[j] saves maximum score among
    grid[0][0]~grid[i][j]. Since score decreases or the same even if we include
    grid[:][j+1:n-1], maintaining dp structure as this is enough. dp[0] =
    2147483647; // first element (grid[0][0]) is not considered for(int j=1;
    j<n; j++) { dp[j] = min(dp[j-1], grid[0][j]);
    }
    // DP (for each row)
    for (int i=1; i<m; i++) {
        dp[0] = min(dp[0], grid[i][0]);
        for(int j=1; j<n; j++) {
            if (i == m - 1 && j == n - 1) {
                dp[j] = max(dp[j - 1], dp[j]); // last element (grid[m-1][n-1])
    is not considered. Only left/up dp value affects. } else { int score1 =
    min(dp[j-1], grid[i][j]); // left: dp[i][j-1] int score2 = min(dp[j],
    grid[i][j]); // up: dp[i-1][j] dp[j] = max(score1, score2);
            }
        }
    }
    return min({dp[n-1], grid[0][0], grid[m-1][n-1]});
    */
  }
};
