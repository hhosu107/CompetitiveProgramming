#include<bits/stdc++.h>

using namespace std;

/* To get at least c amount of people,
 * compute the least amount of price to spend.
 */

bool avail[100001][21];
int people[100001][21];

int main () {
  int c, n;
  cin >> c >> n;
  vector<int> price(n + 1), amount(n + 1);
  for (int i=0; i<n; i++)
    cin >> price[i + 1] >> amount[i + 1];
  avail[0][0] = true;
  int min_price = 100001;
  for(int i=1; i<=100000; i++) {
    for(int j=1; j<=n; j++) {
      for(int k=0; k<=n; k++) {
        if (i >= price[j] && avail[i - price[j]][k]) {
          avail[i][j] = true;
          people[i][j] = max(people[i][j], people[i - price[j]][k] + amount[j]);
        }
      }
      if (people[i][j] >= c) {
        min_price = i;
        break;
      }
    }
    if (min_price < 100001)
      break;
  }
  cout << min_price << endl;
  return 0;
}
