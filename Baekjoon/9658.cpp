#include<bits/stdc++.h>
using namespace std;

/* Each player takes 1, 3, or 4 stones.
 * The last player to take the last stone loses.
 * Decide the winner.
 * Sol) In my turn, if only 2 stones are left, I win.
 * If 4 stones are left, I will take 3 stones and then win.
 * If 3 stones are left, I lose.
 * If 5 stones, I will take 4 stones to win.
 * For others...
 * 6: I will take 3 stones and then win.
 * 7: I will take 4 stones and then win.
 * 8: I lose. If I take 1 stones, then opponent will take 4 stones;
 *    If I take 3 stones, then opponent will take 4 stones;
 *    If I take 4 stones, then opponent will take 3 stones.
 */
int main () {
  int n;
  cin >> n;
  vector<int> winner(n + 1, 0);
  winner[1] = 2;
  for(int i=2; i<=n; i++) {
    if (i == 2 || i == 4 || i == 5) {
      winner[i] = 1;
    } else if (i == 3) {
      winner[i] = 2;
    }
    else winner[i] = ((winner[i-1] == 2 || winner[i-3] == 2 || winner[i-4] == 2) ? 1 : 2);
  }
  cout << (winner[n] == 1 ? "SK\n" : "CY\n");
  return 0;
}
