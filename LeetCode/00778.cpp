
using pii = pair<int, int>;

struct PointWeight {
  int x;
  int y;
  int w;
  PointWeight(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
};

class Solution {
public:
  int swimInWater(vector<vector<int>> &green) {
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int row = green.size();
    int col = green[0].size();
    if (row == 1 && col == 1)
      return 0;
    vector<vector<int>> cost(row, vector<int>(col, -1));
    cost[0][0] = green[0][0];
    auto comp = [](const PointWeight &l, const PointWeight &r) {
      if (l.w != r.w)
        return l.w > r.w;
      return (l.x > r.x || (l.x == r.x && l.y > r.y));
    };
    priority_queue<PointWeight, vector<PointWeight>, decltype(comp)> pq(comp);
    pq.push({0, 0, cost[0][0]});
    while (!pq.empty()) {
      PointWeight curr = pq.top();
      pq.pop();
      for (int i = 0; i < 4; i++) {
        int nx = curr.x + dir[i][0];
        int ny = curr.y + dir[i][1];
        if (0 > nx || row <= nx || 0 > ny || col <= ny)
          continue;
        if (nx == row - 1 && ny == col - 1) {
          return max(cost[curr.x][curr.y], green[nx][ny]);
        }
        if (cost[nx][ny] != -1)
          continue;
        cost[nx][ny] = max(cost[curr.x][curr.y], green[nx][ny]);
        pq.push({nx, ny, cost[nx][ny]});
      }
    }
    // unreachable, but..
    return -1;
  }
};
