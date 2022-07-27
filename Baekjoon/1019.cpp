#include<iostream>
#include<algorithm>
using namespace std;

int main () {
  long long int digit_occ[10] = {0};
  int n;
  cin >> n;
  long long int base = 1;
  int n_divided = n;
  while (n_divided > 0) {
    for(int i=0; i<=9; i++) {
      // if base == 1, there is no loss except 0 for 1 loss.
      // if base == 10^k, the last digit will be added by (n % base + 1) times.
      if (i == 0) {
        if (n_divided % 10 == i) {
          digit_occ[i] += max(base * (n_divided / 10 - 1) + (n % base + 1), 0LL);
        } else {
          digit_occ[i] += base * (n_divided / 10);
        }
      }
      else {
        if (n_divided % 10 > i) {
          digit_occ[i] += base * (n_divided / 10 + 1);
        } else if (n_divided % 10 < i) {
          digit_occ[i] += base * (n_divided / 10);
        } else {
          digit_occ[i] += base * (n_divided / 10) + (n % base + 1);
        }
      }
    }
    n_divided /= 10;
    base *= 10;
  }
  for(int i=0; i<10; i++)
    cout << digit_occ[i] << ' ';
  cout << endl;
  return 0;
}

