#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using plll = pair<ll, pll>;

int main () {
  int n;
  cin >> n;
  vector<ll> val(n);
  for(auto &x: val) cin >> x;
  sort(val.begin(), val.end());
  ll abs_min = 3333333333LL;
  plll ans = make_pair(1111111111LL, make_pair(1111111111LL, 1111111111LL));
  for(int i=0; i<n - 2; i++) {
    ll a = val[i];
    int start = i + 1;
    int end = n - 1;
    while(start < end) {
      ll b = val[start];
      ll c = val[end];
      if (a + b + c == 0) {
        plll p = make_pair(a, make_pair(b, c));
        ans = p;
        abs_min = 0;
        break;
      }
      if (abs_min == 0) break;
      if (abs(a + b + c) < abs(abs_min)) {
        plll p = make_pair(a, make_pair(b, c));
        ans = p;
        abs_min = abs(a + b + c);
      }
      if (a + b + c >= 0) {
        end--;
      } else {
        start++;
      }
    }
    if (abs_min == 0) break;
  }
  cout << ans.first << " " << ans.second.first << " " << ans.second.second << endl;
  return 0;
}
