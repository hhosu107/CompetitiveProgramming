#include<bits/stdc++.h>
using namespace std;

int main () {
  int n, k;
  cin >> n >> k;
  int kpow = 1;
  for(int i=0; i<k; i++)
    kpow *= 2;
  if (n <= kpow) {
    cout << 0 << endl;
    return 0;
  }
  else {
    int diff_bottle = 0;
    int bottle[23] = {0};
    int bottle_idx = 0;
    int m = n;
    while (m > 0) {
      bottle[bottle_idx++] = m % 2;
      diff_bottle += m % 2;
      m /= 2;
    }
    if (diff_bottle <= k) {
      cout << 0 << endl;
      return 0;
    }
    int curr_bottle = 0;
    int needed_bottle_base = 1;
    int bought_bottle = 0;
    while (diff_bottle > k) {
      if (bottle[curr_bottle] == 1) {
        bought_bottle += needed_bottle_base;
        while(bottle[curr_bottle] == 1 && diff_bottle > k) {
          needed_bottle_base *= 2;
          bottle[curr_bottle] = 0;
          diff_bottle -= 1;
          curr_bottle++;
        }
        if (diff_bottle <= k && bottle[curr_bottle] == 1) {
          break;
        }
        bottle[curr_bottle] = 1;
        diff_bottle++;
        if (diff_bottle <= k) {
          break;
        }
      } else {
        curr_bottle++;
        needed_bottle_base *= 2;
      }
    }
    cout << bought_bottle << endl;
    return 0;
  }
}
