#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll inv(int a, int m) {
  ll m0 = m, t, q;
  ll x0 = 0, x1 = 1;
  if (m == 1) return 0;

  // Apply extended euclidean algorithm.
  while (a > 1) {
    // q is quotient.
    q = a / m;
    t = m;
    // m is remainder now.
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  // Make x1 positive.
  if (x1 < 0) x1 += m0;
  return x1;
}

ll chinese_remainder_thm(vector<ll> div, vector<ll> rem) {
  ll prod = 1;
  // Compute product of all numbers
  for (auto d: div) prod *= d;
  // Initialize result
  ll result = 0;
  // Chinese remainder theorem:
  // When every number in div is coprime, assume prod = pi(div).
  // Let pp[i] = prod / div[i] (Product of all but div[i])
  // Let inv[i] = Modular multiplicative inverse of pp[i] w.r.t. div[i],
  // i.e., ( inv[i] * pp[i] ) % div[i] = 1.
  // Then result = sum(pp[i] * inv[i] * rem[i]) % prod.
  for(int i=0; i<div.size(); i++) {
    ll pp = prod / div[i];
    result = (result + pp * rem[i] * inv(pp, div[i])) % prod;
  }
  return result;
}

int main () {
  ll e, s, m;
  cin >> e >> s >> m;
  e--;
  s--;
  m--;
  vector<ll> div = {15, 28, 19};
  vector<ll> rem = {e, s, m};
  cout << chinese_remainder_thm(div, rem) + 1 << endl;
  return 0;
}
