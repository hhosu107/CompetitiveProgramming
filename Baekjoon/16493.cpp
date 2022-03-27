#include<bits/stdc++.h>
using namespace std;

struct chapter {
  int days, pages;
  chapter (int d, int p): days(d), pages(p) {}
  chapter (): days(0), pages(0) {}
  bool operator < (const chapter &c) const {
    return (pages * c.days < c.pages * days) || (pages * c.days == c.pages * days && pages < c.pages);
  }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<chapter> v(m);
  for(auto& i: v)
    cin >> i.days >> i.pages;
  sort(v.rbegin(), v.rend());
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if (v[i-1].days <= j) {
        dp[i][j] = max(v[i-1].pages + dp[i-1][j - v[i-1].days], dp[i-1][j]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout << dp[m][n] << '\n';
  return 0;
}
