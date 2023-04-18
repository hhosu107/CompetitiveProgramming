#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/* LAPS
 * Given L, N, Di, C or A.
 */
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    ll l, n;
    cin >> l >> n;
    ll laps = 0, offset = 0, direction = 1;
    char last_touched = 'I';
    for(int i=0; i<n; i++) {
      ll d;
      char c;
      cin >> d >> c;
      if (i == 0) {
        last_touched = c;
      }
      if (last_touched == c) {
        offset += d;
        if (offset >= l) {
          laps += (offset / l);
          offset %= l;
          last_touched = c;
        }
      } else {
        if (offset > d) {
          offset -= d;
          continue;
        }
        offset = d - offset;
        last_touched = c;
        if (offset >= l) {
          laps += (offset / l);
          offset %= l;
          last_touched = c;
        }
      }
    }
    cout << "Case #" << t << ": " << laps << '\n';
  }
  return 0;
}
