#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int, int>;
using piii = pair<pii, int>;
pii d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pii count_tom_and_days(vii &tom, int n, int m) {
  vii days(n, vi(m, 0));
  queue<pii> q;
  int finished_toms = 0;
  for(int j=0; j<n; j++) {
    for(int k=0; k<m; k++) {
      if(tom[j][k] == 1) {
        days[j][k] = 0;
        q.push({j, k});
      }
      else {
        days[j][k] = 1000000;
      }
    }
  }
  int all_days = 0;
  while(!q.empty()) {
    pii cur = q.front();
    q.pop();
    finished_toms++;
    int i = cur.first;
    int j = cur.second;
    for(int l=0; l<4; l++) {
      int ni = cur.first + d[l].first;
      int nj = cur.second + d[l].second;
      if(ni >= 0 && ni < tom.size() && nj >= 0 && nj < tom[0].size()) {
        if(tom[ni][nj] == 0 || (tom[ni][nj] == 1 && days[ni][nj] > days[i][j] + 1)) {
          days[ni][nj] = days[i][j] + 1;
          all_days = max(all_days, days[ni][nj]);
          q.push({ni, nj});
          tom[ni][nj] = 1;
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

  int m, n;
  cin >> m >> n;
  int total_toms = 0;
  vii tom(n, vi(m, 0));
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < m; k++) {
      cin >> tom[j][k];
      if (tom[j][k] != -1)
      total_toms++;
    }
  }
  pii ans = count_tom_and_days(tom, n, m);
  if (ans.first == total_toms)
    cout << ans.second << '\n';
  else cout << -1 << '\n';
  return 0;
}
