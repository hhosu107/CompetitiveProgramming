#include<bits/stdc++.h>
using namespace std;


struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
  Point operator+= (const Point &p) {
    x += p.x;
    y += p.y;
    return *this;
  }
  Point operator+(const Point &p) {
    return Point(x + p.x, y + p.y);
  }
};

Point dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int bfs(int x, int y, vector<vector<char>> &grid_c, vector<vector<bool>> &visited, unordered_set<char> &key_set) {
  int gathered_docs = 0;
  char init = grid_c[x][y];
  if (visited[x][y]) return 0;
  if (init == '*') return 0;
  if ('A' <= init && init <= 'Z') {
    if (key_set.find(tolower(init)) == key_set.end()) {
      return 0;
    }
    grid_c[x][y] = '.';
  }
  if ('a' <= init && init <= 'z') {
    grid_c[x][y] = '.';
    key_set.insert(init);
  }
  if (init == '$') {
    grid_c[x][y] = '.';
    gathered_docs += 1;
  }
  queue<Point> q;
  q.push({x, y});
  visited[x][y] = true;
  while (!q.empty()) {
    Point q_p = q.front();
    q.pop();
    for(int i=0; i<4; i++) {
      Point next_point = q_p + dir[i];
      if (next_point.x < 0 || next_point.x >= grid_c.size() || next_point.y < 0 || next_point.y >= grid_c[0].size()) {
        continue;
      }
      if (visited[next_point.x][next_point.y]) continue;
      char next_grid = grid_c[next_point.x][next_point.y];
      if (next_grid == '*') continue;
      if ('A' <= next_grid && next_grid <= 'Z') {
        if (key_set.find(tolower(next_grid)) == key_set.end()) {
          continue;
        }
      }
      // openable door, key, or document.
      if ('a' <= next_grid && next_grid <= 'z') {
        key_set.insert(next_grid);
      }
      if (next_grid == '$') {
        gathered_docs += 1;
      }
      grid_c[next_point.x][next_point.y] = '.';
      visited[next_point.x][next_point.y] = true;
      q.push(next_point);
    }
  }
  return gathered_docs;
}

int main () {
  int t;
  cin >> t;
  while(t--) {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    for(string &s: grid)
      cin >> s;
    // Perform BFS on grid, starting from each boundary.
    // If there is no change with the keys when we perform the full bfs, we stop there.
    // Finally, print the number of documents we've collected.
    vector<vector<char>> grid_c(r, vector<char>(c));
    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++)
        grid_c[i][j] = grid[i][j];
    }
    string keys;
    cin >> keys;
    unordered_set<char> key_set;
    int key_set_size = 0;
    for (char c: keys)
      key_set.insert(c);
    int docs_collected = 0;
    do {
      key_set_size = key_set.size();
      vector<vector<bool>> visited(r, vector<bool>(c, false));
      for(int i=0; i<r; i++) {
        int curr_gathered_keys = bfs(i, 0, grid_c, visited, key_set);
        docs_collected += curr_gathered_keys;
        curr_gathered_keys = bfs(i, c - 1, grid_c, visited, key_set);
        docs_collected += curr_gathered_keys;
      }
      for(int j=1; j<c-1; j++) {
        int curr_gathered_keys = bfs(0, j, grid_c, visited, key_set);
        docs_collected += curr_gathered_keys;
        curr_gathered_keys = bfs(r - 1, j, grid_c, visited, key_set);
        docs_collected += curr_gathered_keys;
      }
    } while (key_set_size != key_set.size());
    cout << docs_collected << endl;
  }
  return 0;
}
