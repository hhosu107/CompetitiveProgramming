#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main () {
  vector<ll> primes(1, 0);
  primes[0] = 2;
  for(int i=3; i<10000000; i += 2) {
    bool flag = true;
    for(int j=0; primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) primes.push_back(i);
  }
  vector<ll> almost_primes;
  for(ll p: primes) {
    ll base = p;
    ll curr = p * p;
    for(int n = 2; curr < 100000000000000LL; n++) {
      almost_primes.push_back(curr);
      curr *= p;
    }
  }
  sort(almost_primes.begin(), almost_primes.end());
  int a, b;
  cin >> a >> b;
  auto l = lower_bound(almost_primes.begin(), almost_primes.end(), a);
  auto r = upper_bound(almost_primes.begin(), almost_primes.end(), b);
  cout << (ll)(r - almost_primes.begin()) - (ll)(l - almost_primes.begin()) << endl;
  return 0;
}
