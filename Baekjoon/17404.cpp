#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using pii = pair<int, int>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int trash = 1000000000;
  int n;
  cin >> n;
  vector<vector<int>> coloring(n, vector<int>(3));
  for(int i=0; i<n; i++) {
    for(int j=0; j<3; j++) {
      cin >> coloring[i][j];
    }
  }

  // Idea:
  // Try 3 cases for the second row:
  // Fix the selection of the first row; suppose ith column of the first row has
  // been chosen.
  // Then for the second row, fill the 0th column as trash value; fill the 1st /
  // second column as the sum of first row's 0th column ans second row's ith
  // column.
  // Then compute manually for the rest of the row.
  // When we bring the minimum of this computation, compute minimum of: nth
  // row's 1st column and nth row's 2nd column. Since we only selected the 0th
  // column of 1st row, nth row's 0th column collides with 1st row's selection.
  vector<vector<vector<int>>> cyclic_dp(3, vector<vector<int>>(n, vector<int>(3)));
  int min_cyclic = trash;
  for(int i=0; i<3; i++) {
    cyclic_dp[i][0][i] = coloring[0][i]; // 0th row, ith column.
    cyclic_dp[i][1][i] = trash;
    cyclic_dp[i][1][(i+1)%3] = coloring[0][i] + coloring[1][(i+1)%3]; // For the 1st row, fix 0th row, ith column as the previous one.
    cyclic_dp[i][1][(i+2)%3] = coloring[0][i] + coloring[1][(i+2)%3]; // Same.
    for(int j=2; j<n; j++) {
      for(int k=0; k<3; k++){
        cyclic_dp[i][j][k] = min(cyclic_dp[i][j-1][(k+1)%3], cyclic_dp[i][j-1][(k+2)%3]) + coloring[j][k];
      }
    }
    min_cyclic = min(min_cyclic, min(cyclic_dp[i][n-1][(i+1)%3], cyclic_dp[i][n-1][(i+2)%3])); // For the nth row, compare only 1st/2nd column selection. Then nth row's selection doesn't violate the condition.
  }
  cout << min_cyclic << endl;
  return 0;
}
