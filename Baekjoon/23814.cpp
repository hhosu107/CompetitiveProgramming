#include<iostream>
using namespace std;

typedef long long ll;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll d, n, m, k;
  cin >> d >> n >> m >> k;
  ll gotg = (n / d) + (m / d);
  n %= d;
  m %= d;
  ll kmax = k / d;
  ll kmd = k;
  if (n != 0 && k - (d - n) >= 0) {
    if ((k - (d - n)) / d + 1 > kmax) {
      kmax = (k - (d - n)) / d + 1;
      kmd = k - (d - n);
    }
  }
  if (m != 0 && k - (d - m) >= 0) {
    if (((k - (d - m)) / d + 1 > kmax) || ((k - (d - m)) / d + 1 == kmax) && k - (d - m) > kmd) {
      kmax = (k - (d - m)) / d + 1;
      kmd = k - (d - m);
    }
  }
  if (n != 0 && m != 0 && (k - (d - m) - (d - n) >= 0)) {
    if (((k - (d - n) - (d - m)) / d + 2 > kmax) || ((k - (d - n) - (d - m)) / d + 2) == kmax && k - (d - m) - (d - n) > kmd) {
      kmax = (k - (d - m) - (d - n)) / d + 2;
      kmd = k - (d - m) - (d - n);
    }
  }
  cout << kmd << '\n';
  return 0;
}
