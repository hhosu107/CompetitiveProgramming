#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs_areas(vector<string> &area, int len) {
  vector<vector<int>> visited(len, vector<int>(len, 0));
  int cnt = 0;
  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++) {
      if (visited[i][j]) continue;
      else {
        cnt++;
        queue<pair<int, int>> pts;
        pts.push({i, j});
        while(!pts.empty()) {
          int x = pts.front().first;
          int y = pts.front().second;
          pts.pop();
          if (visited[x][y]) continue;
          else {
            visited[x][y] = 1;
            if (x > 0 && area[x-1][y] == area[x][y]) pts.push({x-1, y});
            if (x < len-1 && area[x+1][y] == area[x][y]) pts.push({x+1, y});
            if (y > 0 && area[x][y-1] == area[x][y]) pts.push({x, y-1});
            if (y < len-1 && area[x][y+1] == area[x][y]) pts.push({x, y+1});
          }
        }
      }
    }
  }
  return cnt;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<string> area(n);
  for(auto& st: area)
    cin >> st;
  int normal_num = bfs_areas(area, n);
  for(auto& st: area) {
    size_t pos;
    while((pos = st.find("G")) != string::npos) {
      st.replace(pos, 1, "R");
    }
  }
  int rg_same_num = bfs_areas(area, n);
  cout << normal_num << " " << rg_same_num << '\n';
  return 0;
}
