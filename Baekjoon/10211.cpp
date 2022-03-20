#include<bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int best = 0;
    int curr = 0;
    bool all_neg = true;
    int neg_best = -999999;
    for(int i=0; i<n; i++) {
      cin >> a[i];
      curr = max(0, curr + a[i]);
      best = max(best, curr);
      if (a[i] >= 0) {
        all_neg = false;
      } else {
        neg_best = max(neg_best, a[i]);
      }
    }
    cout << (all_neg ? neg_best : best) << '\n';
  }
  return 0;
}
