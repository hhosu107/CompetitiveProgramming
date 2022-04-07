#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ppi = pair<pii, int>;

int dd[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
void bfs_fill(vector<vector<int>> &steps, pii start) {
  queue<ppi> q;
  q.push({start, 0});
  steps[start.first][start.second] = 0;
  while(!q.empty()) {
    auto [cur, step] = q.front();
    q.pop();
    for(int i=0; i<8; i++) {
      int nx = cur.first + dd[i][0];
      int ny = cur.second + dd[i][1];
      if(nx < 0 || nx >= steps.size() || ny < 0 || ny >= steps[0].size()) continue;
      if(steps[nx][ny] != -1) continue;
      steps[nx][ny] = step + 1;
      q.push({{nx, ny}, step + 1});
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  pii k;
  cin >> k.first >> k.second;
  vector<pii> e(m);
  for(auto &x: e)
    cin >> x.first >> x.second;
  vector<vector<int>> steps(n + 1, vector<int>(n + 1, -1));
  bfs_fill(steps, k);
  for(auto x: e) {
    cout << steps[x.first][x.second] << ' ';
  }
  cout << '\n';
  return 0;
}
