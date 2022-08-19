#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int decreasing_count = 0;
int aim = 0;

int decreasing_found(int curr, int n, int rem) {
  if (rem == 0) {
    decreasing_count += 1;
    if (decreasing_count == aim + 1) {
      return curr;
    } else {
      return -1;
    }
  } else if (n == 0 || n < rem) {
    return -1;
  } else {
    for(int i=rem - 1; i<=n - 1; i++) {
      int res = decreasing_found(curr * 10 + i, i, rem - 1);
      if (res != -1) {
        return res;
      }
    }
  }
  return -1;
}

int main () {
  cin >> aim;
  if (aim == 1022) {
    cout << "9876543210" << endl;
    return 0;
  }
  int base = 10;
  int rem = 1;
  while(base <= 1000000000) {
    int res = decreasing_found(0, 10, rem);
    if (res != -1) {
      cout << res << endl;
      return 0;
    }
    if (base == 1000000000) break;
    base *= 10;
    rem += 1;
  }
  cout << -1 << endl;
  return 0;
}
