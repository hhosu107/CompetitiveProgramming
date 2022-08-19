#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main () {
  ll n;
  vector<ll> dice(6);
  cin >> n;
  for(ll &d: dice)
    cin >> d;
  ll max_dice = *max_element(dice.begin(), dice.end());
  ll min_dice = *min_element(dice.begin(), dice.end());
  ll min_edge = 2 * max_dice;
  for(ll i=0; i<5; i++) {
    for(ll j=i + 1; j<6; j++) {
      if (i + j == 5) continue;
      min_edge = min(min_edge, dice[i] + dice[j]);
    }
  }
  ll min_corner = 3 * max_dice;
  min_corner = min(min_corner, dice[0] + dice[1] + dice[2]);
  min_corner = min(min_corner, dice[0] + dice[1] + dice[3]);
  min_corner = min(min_corner, dice[0] + dice[2] + dice[4]);
  min_corner = min(min_corner, dice[0] + dice[3] + dice[4]);
  min_corner = min(min_corner, dice[1] + dice[2] + dice[5]);
  min_corner = min(min_corner, dice[1] + dice[3] + dice[5]);
  min_corner = min(min_corner, dice[2] + dice[4] + dice[5]);
  min_corner = min(min_corner, dice[3] + dice[4] + dice[5]);
  if (n == 1) {
    cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4] + dice[5] - max_dice << endl;
  } else {
    cout << 4 * min_corner + (8 * n - 12) * min_edge + ((n - 2) * (n - 2) + 4 * (n - 2) * (n - 1)) * min_dice << endl;
  }
  return 0;
}
