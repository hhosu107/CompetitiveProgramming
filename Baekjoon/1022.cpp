#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int index_to_spiral(int n, int m) {
  if (n == 0 && m == 0) return 1;
  int larger = max(abs(n), abs(m)) - 1;
  int base = (2 * larger + 1) * (2 * larger + 1);
  // spiral starts at (larger + 1, larger) -> (larger + 1, -(larger + 1)), ->
  // (-(larger + 1), -(larger + 1)) -> (-(larger + 1), (larger + 1)) -> ((larger
  // + 1), (larger + 1)).
  if (n == (larger + 1) && m != (larger + 1)) {
    return base + (larger + 1 - m);
  }
  if (m == -(larger + 1)) {
    return base + 2 * larger + 2 + (larger + 1) - n; // m == larger + 1: 0. m == -(larger + 1): 2 * larger + 2.
  }
  if (n == -(larger + 1)) {
    return base + 2 * larger + 2 + 2 * larger + 2 + (larger + 1) + m; // n == larger + 1: 0. n == -(larger + 1): 2 * larger + 2.
  }
  if (m == (larger + 1)) {
    return base + 2 * larger + 2 + 2 * larger + 2 + 2 * larger + 2 + (larger + 1) + n; // m == -(larger + 1): 0. m == (larger + 1): 2 * larger + 2.
  }
  return -1; // unreachable
}
int main () {
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  vector<vector<int>> spiral(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));
  int max_spiral = 0;
  for(int i=r1; i<=r2; i++) {
    for(int j=c1; j<=c2; j++) {
      spiral[i - r1][j - c1] = index_to_spiral(j, i);
      max_spiral = max(max_spiral, spiral[i - r1][j - c1]);
    }
  }
  int base = 1;
  int base_10 = 10;
  while(true) {
    if (max_spiral < base_10) break;
    base += 1;
    base_10 *= 10;
  }
  for(int i=0; i<r2 - r1 + 1; i++) {
    for(int j=0; j<c2 - c1 + 1; j++) {
      cout << setw(base) << spiral[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
