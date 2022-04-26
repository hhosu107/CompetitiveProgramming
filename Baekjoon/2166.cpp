#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

ll area(vector<pll> pts) {
  ll a = 0;
  for(int i=0; i<pts.size(); i++) {
    a += (pts[i].first + pts[(i+1) % pts.size()].first) * (pts[i].second - pts[(i+1) % pts.size()].second);
  }
  return abs(a);
}

int main () {
  // How to induce n-gonal's area? https://darkpgmr.tistory.com/86
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<pll> pts(n);
  for(int i=0; i<n; i++)
    cin >> pts[i].first >> pts[i].second;
  ll a = area(pts);
  cout << fixed << setprecision(1) << (double)(a) / 2.0 << '\n';
  return 0;
}
