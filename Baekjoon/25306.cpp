#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int main () {
  ll a, b;
  cin >> a >> b;
  // Sol) for each digits between [a, b], compute the number of 1s.
  // If odd for each digit, the XOR result for that digit will be 1; o.w., 0.
  vector<ll> one_digit(64);
  ll A = a, B = b;
  ll idx = 0, base = 1;
  while (A >= base || B >= base) {
    // ...
    ll digit_a = A / base;
    ll digit_b = B / base;
    ll digit_under_a = a % base;
    ll digit_under_b = b % base + 1;
    if (digit_a == digit_b) {
      ll possible_count = digit_under_b - digit_under_a;
      if (digit_a % 2 == 1) {
        one_digit[idx] = possible_count;
      } else {
        one_digit[idx] = 0;
      }
    } else {
      ll comp_digit_under_a = base - digit_under_a;
      if (digit_a % 2 == 1) {
        one_digit[idx] = comp_digit_under_a;
      } else {
        one_digit[idx] = 0;
      }
      digit_a += 1;
      ll curr_digit_under_b = digit_under_b;
      if (digit_b % 2 == 1) {
        one_digit[idx] += curr_digit_under_b;
      } else {
        one_digit[idx] += 0;
      }
      // compute digit_b - digit_a. if %2 == 0, base * (digit_b - digit_a) / 2.
      // otherwise, it depends on (digit_a % 2). if (digit_a % 2 == 1), base *
      // ((digit_b - digit_a) /2 + 1), otherwise, (base * ((digit_b - digit_a) /
      // 2))
      ll intermediates = digit_b - digit_a;
      if (intermediates % 2 == 0 || digit_a % 2 == 0) {
        one_digit[idx] += base * (intermediates / 2);
      } else {
        one_digit[idx] += base * (intermediates / 2 + 1);
      }
    }
    idx++;
    base *= 2;
  }
  ll real_base = 1;
  ll res = 0;
  for(int i=0; i<63; i++) {
    res += (one_digit[i] % 2) * real_base;
    real_base *= 2;
  }
  cout << res << endl;
  return 0;
}
