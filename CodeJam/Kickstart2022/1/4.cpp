#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  ll a, b;
  cin >> T;
  /* Small: for every integer \in [a, b], compute product of digits/sum of
   * digits,
   * and find if it is divisible or not.
   */
  for(int t=1; t<=T; t++) {
    cin >> a >> b;
    ll ans = 0;
    for(int i=a; i<=b; i++) {
      ll prod = 1, sum = 0;
      int k = i;
      while(k) {
        int rem = k % 10;
        k /= 10;
        prod *= rem;
        sum += rem;
      }
      if (prod % sum == 0) ans++;
    }
    cout << "Case #" << t << ": " << ans << '\n';
  }
  return 0;
}
