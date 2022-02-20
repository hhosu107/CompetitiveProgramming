#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vector<int>>;
using viii = vector<vector<vector<int>>>;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using piiii = pair<piii, int>;
piii d[6] = {{{1, 0}, 0}, {{-1, 0}, 0}, {{0, 1}, 0}, {{0, -1}, 0}, {{0, 0}, 1}, {{0, 0}, -1}};

pii count_tom_and_days(viii &tom, int h, int n, int m) {
  viii days(h, vii(n, vi(m, 0)));
  queue<piii> q;
  int finished_toms = 0;
  for(int i=0; i<h; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<m; k++) {
        if(tom[i][j][k] == 1) {
          days[i][j][k] = 0;
          q.push({{i, j}, k});
        }
        else {
          days[i][j][k] = 400;
        }
      }
    }
  }
  int all_days = 0;
  while(!q.empty()) {
    piii cur = q.front();
    q.pop();
    finished_toms++;
    int i = cur.first.first;
    int j = cur.first.second;
    int k = cur.second;
    for(int l=0; l<6; l++) {
      int ni = cur.first.first + d[l].first.first;
      int nj = cur.first.second + d[l].first.second;
      int nk = cur.second + d[l].second;
      if(ni >= 0 && ni < tom.size() && nj >= 0 && nj < tom[0].size() && nk >= 0 && nk < tom[0][0].size()) {
        if(tom[ni][nj][nk] == 0 || (tom[ni][nj][nk] == 1 && days[ni][nj][nk] > days[i][j][k] + 1)) {
          days[ni][nj][nk] = days[i][j][k] + 1;
          all_days = max(all_days, days[ni][nj][nk]);
          q.push({{ni, nj}, nk});
          tom[ni][nj][nk] = 1;
        }
      }
    }
  }
  return {finished_toms, all_days};
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m, n, h;
  cin >> m >> n >> h;
  int total_toms = 0;
  viii tom(h, vii(n, vi(m, 0)));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> tom[i][j][k];
        if (tom[i][j][k] != -1)
        total_toms++;
      }
    }
  }
  pii ans = count_tom_and_days(tom, h, n, m);
  if (ans.first == total_toms)
    cout << ans.second << '\n';
  else cout << -1 << '\n';
  return 0;
}
