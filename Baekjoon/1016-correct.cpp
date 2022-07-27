#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<bool> arr;
using ll = long long;
int main () {
  ll m, M;
  cin >> m >> M;
  arr = vector<bool>(M - m + 1, false);
  for(ll i=2; i*i <= M; i++) {
    ll n = m / (i * i);
    if (m % (i * i) != 0) n++; // starting from n * i * i, mark arr[n * i * i - m] as true.
    while (n * i * i <= M) {
      arr[n * i * i - m] = true;
      n += 1;
    }
    // Time complexity: O(1000000 * (sum (1 / n^2))) <= O(1000000 * pi^2 / 6).
  }
  int cnt = 0;
  for(int i=0; i<=M - m; i++) {
    if (!arr[i]) cnt++;
  }
  cout << cnt;
  return 0;
}
