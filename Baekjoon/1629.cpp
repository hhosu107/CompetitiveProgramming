/* Integer powering a^b where b can be large enough. */

#include<iostream>

using namespace std;

using ll = long long;
ll pow(ll a, ll b, ll c) {
  if(b == 0) return 1;
  if(b == 1) return a % c;
  ll ans = pow(a, b/2, c);
  ans = (((ans * ans) % c) * (b % 2 == 1 ? a : 1)) % c;
  return ans;
}

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  ll ans = pow(a, b, c);
  cout << ans << endl;
  return 0;
}
