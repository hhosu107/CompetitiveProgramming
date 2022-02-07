#include<iostream>
#include<cmath>
using namespace std;

int zaccess(int n, int r, int c, int pow) {
  if (n == 0) return 1;
  else {
    if (r < pow) {
      if (c < pow) return zaccess(n - 1, r, c, pow / 2);
      else return zaccess(n - 1, r, c - pow, pow / 2) + pow * pow;
    } else {
      if (c < pow) return zaccess(n - 1, r - pow, c, pow / 2) + 2 * pow * pow;
      else return zaccess(n - 1, r - pow, c - pow, pow / 2) + 3 * pow * pow;
    }
  }
  return 0;
}

int main () {
  int n, r, c;
  cin >> n >> r >> c;
  int p = (int)pow(2, n);
  int ans = zaccess(n, r, c, p / 2);
  cout << ans - 1 << endl;
  return 0;
}
