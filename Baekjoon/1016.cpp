#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

using ll = long long;
vector<ll> primes;

int main () {
  ll m, M;
  cin >> m >> M;
  primes.push_back(2LL);
  primes.push_back(3LL);
  for(int i=5; i<=(ll)(sqrt(M)) + 1; i+=2) {
    bool flag = true;
    for(int j=0; primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) primes.emplace_back(i);
  }
  int tolerate_cnt = 0;
  for(ll i=m; i<=M; i++) {
    bool tolerable = true;
    for(int j=0; (j < primes.size()) && (primes[j] * primes[j] <= i); j++) {
      if (i % (primes[j] * primes[j]) == 0) {
        tolerable = false;
        break;
      }
    }
    if (tolerable) tolerate_cnt++;
  }
  cout << tolerate_cnt << endl;
  return 0;
}
