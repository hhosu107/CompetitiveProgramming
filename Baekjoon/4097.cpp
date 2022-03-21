#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T) {
    vector<ll> a(T);
    ll best = 0;
    ll curr = 0;
    bool all_neg = true;
    ll neg_best = -999999;
    for(int i=0; i<T; i++) {
      cin >> a[i];
      curr = (curr + a[i] > 0 ? curr + a[i] : 0);
      best = max(best, curr);
      if (a[i] >= 0) {
        all_neg = false;
      } else {
        neg_best = max(neg_best, a[i]);
      }
    }
    cout << (all_neg ? neg_best : best) << '\n';
    cin >> T;
  }
  return 0;
}
