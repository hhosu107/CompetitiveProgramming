#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int, int>;

int dd[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int bfs (vector<vector<int>> map) {
  int n = map.size();
  int m = map[0].size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if (map[i][j] == 2) {
        queue<pii> q;
        q.push({i, j});
        while (!q.empty()) {
          auto cur = q.front();
          q.pop();
          for(int k=0; k<4; k++) {
            int x = cur.first + dd[k][0];
            int y = cur.second + dd[k][1];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (map[x][y] == 2) continue;
            if (map[x][y] == 1) continue;
            map[x][y] = 2;
            q.push({x, y});
          }
        }
      }
    }
  }
  int cnt = 0;
  for (int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if (map[i][j] == 0) cnt++;
    }
  }
  return cnt;
}

int main () {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> map(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  int max_cnt = 0;
  for(int i=0; i<n*m; i++) {
    for(int j=i+1; j<n*m; j++) {
      for(int k=j+1; k<n*m; k++) {
        vector<vector<int>> muted_map = map;
        if (muted_map[i/m][i%m] != 0 || muted_map[j/m][j%m] != 0 || muted_map[k/m][k%m] != 0)
          continue;
        muted_map[i/m][i%m] = 1;
        muted_map[j/m][j%m] = 1;
        muted_map[k/m][k%m] = 1;
        int cnt = bfs(muted_map);
        max_cnt = max(max_cnt, cnt);
      }
    }
  }
  cout << max_cnt << endl;
  return 0;
}
