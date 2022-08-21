#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/* coloring
validness: cell == white, adjacent two (one if that cell is the end) cells == white.
Player: minimize the score of the bot.
Bot: colors the first valid cell from the left.
Sol) To minimize the bot's score, player always paints the cell that is located x + 3, where the bot painted x at the last.
Alternatively, bot colors x + 2th cell that x is lastly colored by the player.
Thus, the answer is (ceil)(n / 5) = (n + 4) / 5.
 */

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int n;
    cin >> n;
    cout << "Case #" << t << ": " << (n + 4) / 5 << '\n';
  }
  return 0;
}
