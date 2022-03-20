#include<bits/stdc++.h>
using namespace std;

/* Positive integer N, construct a multiple of 9, by inserting exactly one digit
 * anywhere in the given number N. The number must be a multiple of 9. N does
 * not containing any leading zeros. The result must not contain any leading
 * zeros.
 * What is the minimum number possible?
 * ex) 18 -> 108
 * ex) 170 -> 1170
 * ex) 216 -> 2016
 * ex) 214 -> 2124
 * ex) 150 -> 1350
 * ex) 130 -> 1305
 * ex) 132 -> 1323
 */

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  string n;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n;
    int sum_digits = 0;
    for(char x: n) {
      sum_digits += (int)(x - '0');
    }
    int rem = (9 - (sum_digits % 9));
    rem = (rem == 9) ? 0 : rem;
    cout << "Case #" << t << ": ";
    int index_to_insert = (rem == 0) ? 1 : 0;
    for(; index_to_insert<n.size(); index_to_insert++) {
      if (rem < (int)(n[index_to_insert] - '0'))
        break;
    }
    cout << n.substr(0, index_to_insert) << rem << n.substr(index_to_insert) << '\n';
  }
  return 0;
}
