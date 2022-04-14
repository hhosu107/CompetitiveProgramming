#include<bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> prev(n), next(n);
  for_each(prev.begin(), prev.end(), [](string &s) { cin >> s; });
  for_each(next.begin(), next.end(), [](string &s) { cin >> s; });
  vector<vector<int>> prevd(n, vector<int>(m)), nextd(n, vector<int>(m));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      prevd[i][j] = (int)(prev[i][j] - '0');
      nextd[i][j] = (int)(next[i][j] - '0');
    }
  }
  int flip_cnt = 0;
  for(int i=0; i<n-2; i++) {
    for(int j=0; j<m-2; j++) {
      if (prevd[i][j] != nextd[i][j]) {
        flip_cnt++;
        for(int k=0; k<3; k++) {
          for(int l=0; l<3; l++) {
            prevd[i + k][j + l] = 1 - prevd[i + k][j + l];
          }
        }
      }
    }
    for(int j = max(0, m-2); j<m; j++) {
      if(prevd[i][j] != nextd[i][j]) {
        flip_cnt = -1;
        break;
      }
    }
    if (flip_cnt == -1) break;
  }
  if (flip_cnt == -1) {
    cout << -1 << '\n';
    return 0;
  }
  for(int i=max(0, n-2); i<n; i++) {
    for(int j=0; j<m; j++) {
      if(prevd[i][j] != nextd[i][j]) {
        flip_cnt = -1;
        break;
      }
    }
    if (flip_cnt == -1) break;
  }
  cout << flip_cnt << '\n';
  return 0;
}
