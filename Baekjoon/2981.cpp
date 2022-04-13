#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

vector<ll> primes;
vector<ll> pcounts;

set<ll> factors;

/* BOJ 2981: Given n different numbers, find all numbers s.t.: remainder(n, num) are
 * the same for all numbers.
 * Sol) Compute gcd of all diffs, and compute all factors of that gcd.
 * Computing gcd of all diffs is O(n^2 log (max num)), (for all pairs, compute
 * diff). Or.. maybe we can reduce it to O(n log (max num)).
 * pf) compute diff only with the first element and compute the gcd.
 * Let that gcd as g. Then (diff[i] - diff[0]) % g == 0, which means that
 * (diff[i] - diff[0]) - (diff[j] - diff[0]) % g == 0 for all (i, j),
 * and thus every diff[i] - diff[j] is divisible by g, which means that
 * gcd of all diffs must be bigger than or equal to g,
 * but by definition of gcd, it must be smaller than or equal to g.
 * Thus we can compute gcd of all diffs by computing gcd of only (diff[i] -
 * diff[0])s. Thus it is O(n log (max num)).
 * computing all factors of that gcd is O(sqrt(max num)).
 */

/* With given primes and its ocurrences, compute all factors recursively. */
void possible_primes(vector<int> &pidx, int curr_idx, ll cur_val) {
  if (curr_idx == pidx.size()) {
    factors.insert(cur_val);
  } else {
    ll cur_prime_contrib = 1L;
    for (int i=0; i<=pcounts[pidx[curr_idx]]; i++) {
      possible_primes(pidx, curr_idx + 1, cur_val * cur_prime_contrib);
      cur_prime_contrib *= primes[pidx[curr_idx]];
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> diff(n * (n - 1) / 2);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    for(int j = 0; j < i; j++)
      diff[j + i * (i - 1) / 2] = abs(a[i] - a[j]);
  }
  sort(diff.begin(), diff.end());
  ll g = diff[0];
  if (n > 2) {
    for(int i=1; i<n * (n - 1) / 2; i++) {
      if (diff[i] != g) {
        g = gcd(diff[i], g);
      }
    }
  }
  primes.push_back(2);
  for(int i=3; i * i <= g; i += 2) {
    bool isprime = true;
    for(int j=0; j<primes.size() && primes[j] * primes[j] <= g; j++) {
      if (g % primes[j] == 0) {
        isprime = false;
        break;
      }
    }
    if (isprime)
      primes.push_back(i);
  }
  pcounts = vector<ll>(primes.size(), 0);
  ll gt = g;
  /* Compute all factors: You do not need to compute all primes to do that,
   * since x = i * j leads both i and j to be factors of x.
   * Thus it requires only O(sqrt(x)) time to compute all factors.
   */
  queue<ll> q;
  stack<ll> s;
  for(int i=2; i*i<=g; i++) {
    if (g % i == 0) {
      q.push(i);
      if (i * i != g) s.push(g / i);
    }
  }
  vector<ll> factors = vector<ll>();
  while(!q.empty()) {
    factors.push_back(q.front());
    q.pop();
  }
  while(!s.empty()) {
    factors.push_back(s.top());
    s.pop();
  }
  factors.push_back(g);
  /*
  for(int i=0; i<primes.size(); i++) {
    while (gt % primes[i] == 0) {
      gt /= primes[i];
      pcounts[i]++;
    }
    if (gt == 1) break;
  }
  if (gt != 1) {
    primes.push_back(gt);
    pcounts.push_back(1);
  }
  vector<int> pidx;
  for(int i=0; i<pcounts.size(); i++) {
    if (pcounts[i] > 0)
      pidx.push_back(i);
  }
  possible_primes(pidx, 0, 1);
  for(auto el: factors) {
    if (el == 1) continue;
    cout << el << " ";
  }
  cout << '\n';
  */
  for(auto f: factors)
    cout << f << " ";
  cout << '\n';
  return 0;
}

