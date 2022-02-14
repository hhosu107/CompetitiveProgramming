#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int x, int y) {
  if (x == 0) return y;
  if (x > y) return gcd(y, x);
  return gcd(y % x, x);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m, n, x, y;
  int t;
  cin >> t;
  while(t > 0) {
    t--;
    cin >> m >> n >> x >> y;
    int init = min(x, y);
    int find = init;
    int delta = (init == x ? m : n);
    int gc = gcd(m, n);
    int lc = m * n / gc;
    bool found = false;
    for(int i = init; i <= lc; i += delta) {
      if (find == (x + y) - init) {
        cout << i << endl;
        found = true;
        break;
      } else {
        find = (find + delta - 1) % (m + n - delta) + 1;
      }
    }
    if(!found) cout << -1 << endl;
  }
  return 0;
}
