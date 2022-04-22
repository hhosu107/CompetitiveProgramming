#include<bits/stdc++.h>
using namespace std;

using ll = long long;

using pll = pair<ll, ll>;

ll mod_base = 1000000007;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll power(ll x, ll exponent, ll modulo) {
  if (exponent == 0) {
    return 1;
  }
  ll p = power(x, exponent / 2, modulo) % modulo;
  p = (p * p) % modulo;
  return (exponent % 2) == 0 ? p : (x * p) % modulo;
}

ll mod_inverse(ll a) {
  if (gcd(a, mod_base) != 1) return 0;
  return power(a, mod_base - 2, mod_base);
}

int main () {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<pll> dices(n);
  for(auto &d: dices)
    cin >> d.first >> d.second;
  // Fermat's little theorem: a^(p-1) = 1 (mod p) if (p is prime and a % p != 0)
  // Therefore, a^(p-2) = a^(-1) (mod p) for the same condition.
  // Here, we have to compute x/y === x * y^(p-2) (mod p).
  // dice (x, y) means: it has x faces and its sum is y.
  ll modsum = 0;
  for(auto d: dices) {
    modsum += d.second * mod_inverse(d.first);
    modsum %= mod_base;
  }
  cout << modsum << '\n';
  return 0;
}
