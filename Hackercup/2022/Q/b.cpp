#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
 * R*C canvas, zero or more happy little trees, zero or more rocks.
 * To make sure none of his trees lonely, add many trees as I like (possibly 0) to empty spaces
 * so that each tree in the final painting has at least two tree friends.
 * friends: adjacent each other.
 */
/* Sol) Can it be solved with dfs/bfs?
 * Or should we use priority queue?
 * Or just topological sorting?
 */

vector<string> grid;
vector<vector<int>> free_adj_cells;
vector<vector<bool>> invalid_cells;

using pii = pair<int, int>;

void solve(int t) {
  int R, C;
  cin >> R >> C;
  grid = vector<string>(R);
  free_adj_cells = vector<vector<int>>(R, vector<int>(C, -1));
  invalid_cells = vector<vector<bool>>(R, vector<bool>(C, false));
  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  queue<pii> invalid_indices;
  bool tree_invalid_found = false; // turns true if any tree('^') becomes
                                   // invalid
  for(string &g: grid)
    cin >> g;
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      if (grid[i][j] == '#') {
        invalid_cells[i][j] = true;
        continue;
      }
      int free_adj = 0;
      for(int k=0; k<4; k++) {
        int nx = i + dir[k][0], ny = j + dir[k][1];
        if (nx < 0 || R <= nx || ny < 0 || C <= ny) continue;
        if (grid[nx][ny] == '#') continue;
        free_adj += 1;
      }
      free_adj_cells[i][j] = free_adj;
      if (free_adj <= 1) {
        invalid_cells[i][j] = true;
        invalid_indices.push({i, j});
        if (grid[i][j] == '^') tree_invalid_found = true;
      }
    }
  }
  cout << "Case #" << t << ": ";
  if (tree_invalid_found) {
    cout << "Impossible\n";
    return;
  }
  while(!invalid_indices.empty()) {
    pii cur = invalid_indices.front();
    invalid_indices.pop();
    for(int k=0; k<4; k++) {
      int nx = cur.first + dir[k][0], ny = cur.second + dir[k][1];
      if (nx < 0 || R <= nx || ny < 0 || C <= ny) continue;
      if (grid[nx][ny] == '#') continue;
      free_adj_cells[nx][ny] -= 1;
      if (invalid_cells[nx][ny]) continue;
      if (free_adj_cells[nx][ny] <= 1) {
        invalid_cells[nx][ny] = true;
        invalid_indices.push({nx, ny});
        if (grid[nx][ny] == '^') {
          tree_invalid_found = true;
          break;
        }
      }
    }
    if (tree_invalid_found) break;
  }
  if (tree_invalid_found) {
    cout << "Impossible\n";
    return;
  }
  cout << "Possible\n";
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      if (!invalid_cells[i][j]) {
        cout << '^';
      } else {
        cout << grid[i][j];
      }
    }
    cout << '\n';
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    solve(t);
  }
  return 0;
}
