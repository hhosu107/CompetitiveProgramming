#include<iostream>
#include<vector>
using namespace std;

bool diff(int n) {
  if (n < 100) return true;
  int digit_diff = n % 10 - (n / 10) % 10;
  int prev_digit = 0;
  int curr_digit = (n / 10) % 10;
  n /= 100;
  while(n > 0) {
    prev_digit = curr_digit;
    curr_digit = n % 10;
    if (digit_diff != prev_digit - curr_digit) return false;
    n /= 10;
  }
  return true;
}

int main () {
  int n;
  cin >> n;
  int cnt = 0;
  for(int i=1; i<=n; i++)
    if (diff(i)) cnt++;
  cout << cnt << endl;
  return 0;
}
