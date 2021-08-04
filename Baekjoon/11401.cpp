#include<iostream>
#include<algorithm>

typedef long long ll;
const ll P = 1000000007LL;
ll fac[4000001], n, k, inv[4000001];
// Note: 1 === a^(P-1) (mod P). 1 / (a) === a^(P-2).
// i.e., (n!) / (k! (n-k)!) === (n!) * (k!)^(P-2) * ((n-k)!)^(P-2).
using namespace std;

ll power(ll b, ll k) {
  ll ret = 1;
  while(k > 0) {
    if (k % 2 == 1){
      ret *= b;
      ret %= P;
    } // Represent k as a binary representation; k_n-1...k_0. if k_i = 1, ret *= b^(2^i), which is traced by b *= b.
    b *= b;
    b %= P;
    k /= 2;
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  fac[1] = 1;
  for(int i=2; i<=4000000; i++)
    fac[i] = (fac[i-1] * i) % P;
  inv[4000000] = power(fac[4000000], P - 2);
  for(int i=3999999; i>=0; i--){
    inv[i] = (inv[i+1] * (i+1)) % P;
  }
  /* Why does it work?
   * inv[i+1] = ((i+1)!)^(P-2) % P.
   * inv[i] = (i!)^(P-2) % P == (i!)^(P-2) * (i+1)^(P-1) % P By Fermat's thm == (i+1)!^(P-2) * (i+1) % P = inv[i+1] * (i + 1) % P.
   */
  int n, k;
  cin >> n >> k;
  if (n == k || k == 0){
    cout << "1\n";
    return 0;
  }
  ll r = (((fac[n] * inv[n-k]) % P) * inv[k]) % P;
  cout << r << '\n';
  return 0;
}
