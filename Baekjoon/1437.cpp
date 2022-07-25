// Sol) 갯수: round(sqrt(n)), 값들: one of [ceiling(sqrt(n)), floor(sqrt(n))]일
// 때 max.
// 10: 3 * 3 * 4, 11 : 3 * 4 * 4, 12 : 4 * 4 * 4 = lower * upper.

#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

int main () {
  int n;
  cin >> n;
  if (n <= 4) {
    cout << n << endl;
    return 0;
  }
  int three_prod = 1;
  int rem = n % 3;
  for(int i=0; i<n / 3 - 1; i++) {
    three_prod *= 3;
    three_prod %= 10007;
  }
  if (rem == 0) {
    cout << (three_prod * 3) % 10007 << endl;
  } else if (rem == 1) {
    cout << (three_prod * 4) % 10007 << endl;
  } else {
    cout << (three_prod * 3 * 2) % 10007 << endl;
  }
  return 0;
}
