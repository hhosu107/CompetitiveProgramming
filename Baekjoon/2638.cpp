#include<bits/stdc++.h>
using namespace std;

int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
using pii = pair<int, int>;
void bfs_outer_air(vector<vector<int>>& graph) {
  queue<pii> q;
  q.push({0, 0});
  graph[0][0] = -1;
  while (!q.empty()) {
    pii cur = q.front();
    q.pop();
    for(int i=0; i<4; i++) {
      int nx = cur.first + dd[i][0];
      int ny = cur.second + dd[i][1];
      if (0 > nx || nx >= graph.size() || 0 > ny || ny >= graph[0].size()) continue;
      if (graph[nx][ny] != 0) continue;
      graph[nx][ny] = -1;
      q.push({nx, ny});
    }
  }
  for(auto &row: graph) {
    for(auto &cell: row) {
      if (cell == 0)
        cell = 1;
    }
  }
  for(int i=1; i<graph.size() - 1; i++) {
    for(int j=1; j<graph[0].size() - 1; j++) {
      if (graph[i][j] != 1) continue;
      int air_count = 0;
      for(int k=0; k<4; k++) {
        int nx = i + dd[k][0];
        int ny = j + dd[k][1];
        if (graph[nx][ny] == -1) air_count++;
      }
      if (air_count >= 2) graph[i][j] = 2;
    }
  }
}

int main () {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> maps(n, vector<int>(m));
  int cheeze_count = 0;
  for(auto &row: maps) {
    for(auto &cell: row) {
      cin >> cell;
      if (cell == 1) cheeze_count += 1;
    }
  }
  int days = 0;
  while(cheeze_count > 0) {
    vector<vector<int>> change_map = maps;
    bfs_outer_air(change_map);
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(change_map[i][j] == 2) {
          maps[i][j] = 0;
          cheeze_count--;
        }
      }
    }
    days++;
  }
  cout << days << endl;
  return 0;
}
