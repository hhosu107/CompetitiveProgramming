#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using pii = pair<int, int>;
vector<pii> I = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
vector<pii> O = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
vector<pii> L = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
vector<pii> J = {{0, 1}, {1, 1}, {2, 1}, {2, 0}};
vector<pii> S = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
vector<pii> Z = {{0, 1}, {1, 1}, {1, 0}, {2, 0}};
vector<pii> T = {{0, 0}, {0, 1}, {0, 2}, {1, 1}};
vector<vector<pii>> shapes = {I, O, L, J, S, Z, T};

vector<pii> rotate(vector<pii> v, int n) {
  for(auto &pt: v) {
    for(int i=0; i<n; i++) {
      int x = pt.first, y = pt.second;
      pt.first = y;
      pt.second = -x;
    }
  }
  int xmin = v[0].first, ymin = v[0].second;
  for(auto pt: v) {
    xmin = min(xmin, pt.first);
    ymin = min(ymin, pt.second);
  }
  for(auto &pt: v) {
    pt.first -= xmin;
    pt.second -= ymin;
  }
  return v;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m));
  for(auto &i : board){
    for(auto &j : i)
      cin >> j;
  }
  int ans = 0;
  /*
  for(auto shape: shapes) {
    for(int r=0; r<=3; r++) {
      vector<pii> v = rotate(shape, r);
      cout << "r=" << r << ":" << '\n';
      for(pii p: v)
        cout << "(" << p.first << "," << p.second << "),";
      cout << '\n';
    }
  }
  */
  for(auto shape: shapes) {
    for(int r=0; r<=3; r++) {
      vector<pii> used_shape = rotate(shape, r);
      for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
          int sum = 0;
          bool valid_cover = true;
          for(pii pt: used_shape) {
            int x = i + pt.first, y = j + pt.second;
            if (x >= n || y >= m) {
              valid_cover = false;
              break;
            }
            else sum += board[x][y];
          }
          if (valid_cover) ans = max(ans, sum);
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
