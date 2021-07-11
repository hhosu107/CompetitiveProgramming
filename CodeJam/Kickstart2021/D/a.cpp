#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// A. Smaller Strings
// 3*3 grid integers G_i,j. G1,1 is missing.
// Find max number of rows/columns/diagonals of this square, that form sequences which are arithmetic progressions.
// Can replace the missing number with any int.
// Arith prog: a_n = a_n-1 + d for all n.
// Sol) Already 4 seqs are set. Try 4 possible sequences for \, /, -, | that acrosses the center.

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int ans = 0;
    int grid[3][3];
    grid[1][1] = 0;
    for(int i=0; i<3; i++){
      for (int j=0; j<(i == 1 ? 2 : 3); j++){
        cin >> grid[i][(i == 1 ? 2 * j : j)];
      }
    }
    if (grid[0][0] + grid[0][2] == 2 * grid[0][1]) ans++;
    if (grid[0][0] + grid[2][0] == 2 * grid[1][0]) ans++;
    if (grid[2][0] + grid[2][2] == 2 * grid[2][1]) ans++;
    if (grid[0][2] + grid[2][2] == 2 * grid[1][2]) ans++;
    int centerans = 0;
    for(int i=0; i<4; i++){
      int candans = 0;
      int sum = grid[i/3][i%3] + grid[(8-i)/3][(8-i)%3];
      if (sum % 2 != 0) continue;
      int candcent = sum / 2;
      candans = 1;
      for(int j=0; j<4; j++){
        if (i == j) continue;
        int othersum = grid[j/3][j%3] + grid[(8-j)/3][(8-j)%3];
        if (othersum == sum) candans++;
      }
      if (centerans < candans) centerans = candans;
    }
    cout << "Case #" << t << ": " << ans + centerans << "\n";
  }
  return 0;
}
