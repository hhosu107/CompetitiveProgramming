#include<iostream>
#include<vector>
#include<initializer_list>
#include<algorithm>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<int>> dp(2, vector<int>(m));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++)
      cin >> grid[i][j];
  }
  for(int i=0; i<m; i++) {
    dp[(n-1)%2][i] = grid[n-1][i];
  }
  for(int i=n-2; i>=0; i--) {
    for(int j=0; j<m; j++) {
      int result = grid[i][j];
      int prev = 0;
      for(int col=j-1; col<=j+1; col++) {
        if (col >= 0 && col < m) {
          prev = max(prev, dp[(i+1)%2][col]);
        }
      }
      dp[i%2][j] = prev + result;
    }
  }
  cout << dp[0][0] << endl;
}
