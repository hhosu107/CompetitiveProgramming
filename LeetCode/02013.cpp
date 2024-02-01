class DetectSquares {
public:
  // Sol) Since grid is at most 1000 by 1000, generate a grid, record count for
  // each add query, and try each point in grid whether or not they are on the
  // diagonal. If they are diagnoal, since we have both x/y point, compute
  // number of points in this.
  int grid[1001][1001] = {};
  vector<pair<int, int>> points;
  DetectSquares() { points = vector<pair<int, int>>(); }

  void add(vector<int> point) {
    points.emplace_back(point[0], point[1]);
    grid[point[0]][point[1]]++;
  }

  int count(vector<int> point) {
    int ans = 0;
    int x1 = point[0], y1 = point[1];
    for (const auto &[x3, y3] : points) {
      if (abs(x1 - x3) == 0 || abs(x1 - x3) != abs(y1 - y3)) {
        continue;
      }
      // point and queried point are on the diagonal.
      ans += grid[x1][y3] * grid[x3][y1];
    }
    return ans;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
