#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

bool check(int x, int y, vector<vector<bool>> &visit) {
  // Check for previous cells
  for(int i=1; i<=x; i++) {
    if (x - i >= 0 && y - i >= 0) { // Left up direction
      if (visit[x-i][y-i]) return false;
    }
    if (x - i >= 0 && y + i < visit.size()) { // Right up direction
      if (visit[x-i][y+i]) return false;
    }
  }
  return true;
}

int dfs(vector<pair<int, int>> &valid, int depth, int cnt, vector<vector<bool>> &visit) {
  if (depth == valid.size()) {
    return cnt;
  }
  int nx = valid[depth].first;
  int ny = valid[depth].second;
  int curr_pick_cnt = 0;
  // Check colision with other bishop
  if (check(nx, ny, visit)) {
    visit[nx][ny] = true;
    curr_pick_cnt = dfs(valid, depth + 1, cnt + 1, visit);
    visit[nx][ny] = false;
  }
  int curr_notpick_cnt = dfs(valid, depth + 1, cnt, visit);
  return max(curr_pick_cnt, curr_notpick_cnt);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> plate(n, vector<int>(n));
  vector<pii> black_1, white_1;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> plate[i][j];
      if (plate[i][j] == 1) {
        if ((i + j) % 2 == 0) black_1.push_back({i, j});
        else white_1.push_back({i, j});
      }
    }
  }
  // DFS to find maximum number of bishops on black side
  vector<vector<bool>> visit(n, vector<bool>(n, false));
  int black_max = dfs(black_1, 0, 0, visit);
  // DFS to find maximum number of bishops on white side
  visit = vector<vector<bool>>(n, vector<bool>(n, false));
  int white_max = dfs(white_1, 0, 0, visit);
  cout << black_max + white_max << '\n';
  return 0;
}
