#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &visited, vector<string> &grid) {
  int n = visited.size(), m = visited[0].size();
  vector<int> visitible_sizes;
  int visited_idx = 0;
  int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if (visited[i][j] == -1 && grid[i][j] != '1') {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = visited_idx;
        int visited_count = 0;
        while(!q.empty()) {
          pair<int, int> curr = q.front();
          q.pop();
          visited_count += 1;
          for(int k=0; k<4; k++) {
            int nx = curr.first + dir[k][0];
            int ny = curr.second + dir[k][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] >= 0) continue;
            if (grid[nx][ny] == '1') continue;
            visited[nx][ny] = visited_idx;
            q.push({nx, ny});
          }
        }
        visitible_sizes.push_back(visited_count);
        visited_idx += 1;
      }
    }
  }
  return visitible_sizes;
}

void fill_movable_cells(vector<vector<int>> &visited, vector<int> &visitible_sizes, vector<vector<int>> &ans) {
  int n = visited.size(), m = visited[0].size();
  int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if (visited[i][j] >= 0) continue;
      unordered_set<int> visited_set;
      for(int k=0; k<4; k++) {
        if (i + dir[k][0] < 0 || i + dir[k][0] >= n || j + dir[k][1] < 0 || j + dir[k][1] >= m) continue;
        if (visited[i + dir[k][0]][j + dir[k][1]] >= 0) {
          visited_set.insert(visited[i + dir[k][0]][j + dir[k][1]]);
        }
      }
      for (int v: visited_set)
        ans[i][j] += visitible_sizes[v];
      ans[i][j] += 1;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for(string &r: grid)
    cin >> r;
  vector<vector<int>> visited(n, vector<int>(m, -1));
  vector<vector<int>> ans(n, vector<int>(m));
  vector<int> visitible_sizes = bfs(visited, grid);
  fill_movable_cells(visited, visitible_sizes, ans);
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << ans[i][j] % 10;
    }
    cout << '\n';
  }
  return 0;
}
