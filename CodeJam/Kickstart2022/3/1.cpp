#include<bits/stdc++.h>
using namespace std;

/* Speed typing. Making mistakes.
 * Produces P. How many extra letters do you need to delete to get the same
 * string I?
 * It's possible that I cannot be recovered from P.
 * Help to find out how many extra letters to remove. If it cannot be done,
 * print IMPOSSIBLE.
 */

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  int L;
  string P;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> L >> P;
    int plen = P.length();
    cout << "Case #" << t << ": " << P;
    bool detected[4] = {false, false, false, false};
    for(char c: P) {
      if (c == '#' || c == '@' || c == '*' || c == '&')
        detected[3] = true;
      if (c-'0' >= 0 && c-'0' <= 9)
        detected[2] = true;
      if (c-'A' >= 0 && c-'A' <= 25)
        detected[1] = true;
      if (c-'a' >= 0 && c-'a' <= 25)
        detected[0] = true;
    }
    if (!detected[0]) {
      cout << 'a';
      plen++;
    }
    if (!detected[1]) {
      cout << 'A';
      plen++;
    }
    if (!detected[2]) {
      cout << '0';
      plen++;
    }
    if (!detected[3]) {
      cout << '#';
      plen++;
    }
    if (plen < 7) {
      cout << string(7-plen, '#');
    }
    cout << '\n';
  }
  return 0;
}
