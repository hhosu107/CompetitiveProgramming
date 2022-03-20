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
  string I, P;
  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> I >> P;
    int il = I.length(), pl = P.length();
    int iidx = 0, pidx = 0;
    int removed_chars = 0;
    while(pidx < pl && iidx < il) {
      if (P[pidx] == I[iidx]) {
        pidx++;
        iidx++;
      } else {
        pidx++;
        removed_chars++;
      }
    }
    cout << "Case #" << t << ": ";
    if (iidx != il) {
      cout << "IMPOSSIBLE" << '\n';
    } else {
      if (pidx != pl) {
        cout << removed_chars + (pl - pidx) << '\n';
      } else cout << removed_chars << '\n';
    }
  }
  return 0;
}
