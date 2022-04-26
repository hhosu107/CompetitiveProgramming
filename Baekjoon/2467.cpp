#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  for(auto &i: a) cin >> i;
  pll ans = make_pair(1000000000, -1000000000);
  ll diff = -2000000000;
  int l = 0, r = n-1;
  while(l < r) {
    ll sum = a[l] + a[r];
    if (abs(sum) < abs(diff)) {
      diff = sum;
      ans = make_pair(a[l], a[r]);
    }
    if (sum < 0) {
      l++;
    } else {
      r--;
    }
  }
  cout << ans.first << " " << ans.second << '\n';
  return 0;
}
