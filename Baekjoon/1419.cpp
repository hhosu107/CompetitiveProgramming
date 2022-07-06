#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  // Sol)
  // 항 2개의 합: 3 ~ 1000000000
  // 항 3개의 합: 3의 배수 except 3
  // 항 4개의 합: 4k + 2 except k = 1, 4k except k = 1, 2, 3.
  // 항 5개의 합: 5의 배수 except 5, 10.
  int l, r, k;
  cin >> r >> l >> k;
  if (k == 2) {
    int cnt = max((l - max(r, 3) + 1), 0);
    cout << cnt << endl;
    return 0;
  }
  if (k == 3) {
    int l3 = l - (l%3);
    int r3 = max(r + (r%3 == 0 ? 0 : 3 - (r%3)), 6);
    if (l3 - r3 < 0) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << (l3 - r3) / 3 + 1 << endl;
      return 0;
    }
  }
  if (k == 4) {
    int r2 = max(10, r + r%2);
    int l2 = l - l%2;
    if (l2 - r2 < 0) {
      cout << 0 << endl;
      return 0;
    } else if (r2 <= 12 && l2 >= 12) {
      cout << (l2 - r2) / 2 << endl;
      return 0;
    } else {
      cout << (l2 - r2) / 2 + 1 << endl;
      return 0;
    }
  }
  if (k == 5) {
    int l5 = l - (l % 5);
    int r5 = max(r + (r%5 == 0 ? 0 : 5 - (r%5)), 15);
    if (l5 - r5 < 0) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << (l5 - r5) / 5 + 1 << endl;
      return 0;
    }
  }
  return 0;
}
