#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

/* A. Go from (0, 0) to (X, Y), few jumps allowed, land on exact goal point.
 * Expogo stick moves you 2^(i-1) units in the chosen direction.
 * Determine whether it is possible to get there and demonstrate how to do.
 * -10^9 <= X, Y <= 10^9.
 *  Sol) Move to each 4 direction, rescale by half, and check if there are any case that rescaled one has (even, odd) or (odd, even). (Since on each step, we have the only chance to make rescaled point still on the integer point.)
 *  Go until (0, 1), (0, -1), (1, 0), or (-1, 0) appears.
 *  https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62
 */
typedef long long int ll;
ll X, Y;
char ver[4] = "N S";
char hor[4] = "E W";
string movement(ll ax, ll ay, vector<int> &digit, ll power, ll up, ll absum){
  int asign = (X + ax == 0 ? -1 : 1);
  int bsign = (Y + ay == 0 ? -1 : 1);
  for(int i=0; i<up; i++){
    if (abs(ax) < abs(bx)) {

    }
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> X >> Y;
    ll ax = (x > 0 ? x : -x), ay = (y > 0 ? y : -y);
    ll absum = ax + ay;
    vector<int> digit = vector<int>();
    ll power = 1;
    ll up = 0;
    ll sum = absum;
    while(1){
      digit.append(sum%2);
      sum /= 2;
      up += 1;
      if (sum == 0) break;
      power *= 2;
    }
    reverse(digit.begin(), digit.end());
    cout << "Case #" << t << ": ";
  }
  return 0;
}
