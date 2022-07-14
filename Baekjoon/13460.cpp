#include<bits/stdc++.h>
using namespace std;
class Point {
public:
  int x;
  int y;
  Point() : x(-1), y(-1) {}
  Point(int _x, int _y) : x(_x), y(_y) {}
  void operator=(const Point &o) {
    x = o.x;
    y = o.y;
  }
  Point operator+(const Point &o) {
    Point ret(x + o.x, y + o.y);
    return ret;
  }
  Point operator-(const Point &o) {
    Point ret(x - o.x, y - o.y);
    return ret;
  }
  bool operator==(const Point &o) const {
    return (x == o.x) && (y == o.y);
  }
};

Point xMax(Point a, Point b) {
  if (a.x != b.x) return a.x > b.x ? a : b;
  return a.y > b.y ? a : b;
}
Point xMin(Point a, Point b) {
  if (a.x != b.x) return a.x < b.x ? a : b;
  return a.y < b.y ? a : b;
}
Point yMax(Point a, Point b) {
  if (a.y != b.y) return a.y > b.y ? a : b;
  return a.x > b.x ? a : b;
}
Point yMin(Point a, Point b) {
  if (a.y != b.y) return a.y < b.y ? a : b;
  return a.x < b.x ? a : b;
}

struct State {
  vector<vector<char>> board;
  Point red, blue, hole;
  int turns;
  State() : turns(0) {}
  State(vector<vector<char>> board, Point red, Point blue, Point hole, int turns)
      : board(board), red(red), blue(blue), hole(hole), turns(turns) {}
  State(const State &o)
      : board(o.board), red(o.red), blue(o.blue), hole(o.hole), turns(o.turns) {}
  void operator=(const State &o) {
    board = o.board;
    red = o.red;
    blue = o.blue;
    hole = o.hole;
    turns = o.turns;
  }
};

int bfs(vector<vector<char>> board, Point red, Point blue, Point hole, int n, int m) {
  queue<State> q;
  Point dir[4] = {Point(0, 1), Point(0, -1), Point(1, 0), Point(-1, 0)};
  q.push({board, red, blue, hole, 0});
  while (!q.empty() && q.front().turns <= 9) {
    State cur(q.front());
    q.pop();
    for(int i=0; i<4; i++) {
      Point first = Point(), second = Point();
      if (i == 0) {
        first = yMax(cur.red, cur.blue);
      } else if (i == 1) {
        first = yMin(cur.red, cur.blue);
      } else if (i == 2) {
        first = xMax(cur.red, cur.blue);
      } else {
        first = xMin(cur.red, cur.blue);
      }
      second = (cur.red + cur.blue) - first;
      bool red_first = (first == cur.red);
      vector<vector<char>> new_board(cur.board);
      bool red_fell = false, blue_fell = false;
      Point next_first = first + dir[i];
      while (next_first.x >= 0 && next_first.x < n && next_first.y >= 0 && next_first.y < m) {
        if (new_board[next_first.x][next_first.y] == 'O') {
          if (red_first) {
            red_fell = true;
          } else {
            blue_fell = true;
          }
          break;
        }
        else if (new_board[next_first.x][next_first.y] != '.') {
          next_first = next_first - dir[i];
          break;
        }
        next_first = next_first + dir[i];
      }
      new_board[first.x][first.y] = '.';
      if (red_first && !red_fell) {
        new_board[next_first.x][next_first.y] = 'R';
      } else if (!red_first && !blue_fell) {
        new_board[next_first.x][next_first.y] = 'B';
      }
      Point next_second = second + dir[i];
      while (next_second.x >= 0 && next_second.x < n && next_second.y >= 0 && next_second.y < m) {
        if (new_board[next_second.x][next_second.y] == 'O') {
          if (!red_first) {
            red_fell = true;
          } else {
            blue_fell = true;
          }
          break;
        }
        else if (new_board[next_second.x][next_second.y] != '.') {
          next_second = next_second - dir[i];
          break;
        }
        next_second = next_second + dir[i];
      }
      new_board[second.x][second.y] = '.';
      if (!red_first && !red_fell) {
        new_board[next_second.x][next_second.y] = 'R';
      } else if (red_first && !blue_fell) {
        new_board[next_second.x][next_second.y] = 'B';
      }
      if (red_fell && !blue_fell) return cur.turns + 1;
      else if (blue_fell) continue;
      if (cur.board == new_board) continue;
      q.push({
          new_board,
          red_first ? next_first : next_second,
          red_first ? next_second : next_first,
          hole,
          cur.turns + 1
          });
    }
  }
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> str_map(n);
  for(string &s: str_map) cin >> s;
  vector<vector<char>> char_map(n, vector<char>(m));
  Point red, blue, hole;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char_map[i][j] = str_map[i][j];
      if (char_map[i][j] == 'R') red = Point(i, j);
      if (char_map[i][j] == 'B') blue = Point(i, j);
      if (char_map[i][j] == 'O') hole = Point(i, j);
    }
  }
  int res = bfs(char_map, red, blue, hole, n, m);
  cout << res << endl;
  return 0;
}
