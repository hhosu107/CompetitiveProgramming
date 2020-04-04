#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* A. Latin square (N*N matrix) if each cell contains 1 of N different values, not value is repeated within a row or a column.
 * Natural latin squares: all values are between 1~N.
 * Compute trace, check whether latin or not. (If a row contains repeated value, print that in the natural number. If a column contains repeated value, print that in the natural number.)
 */
int a[101][101];
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++){
    cin >> N;
    int row=0, col=0;
    int trace = 0;
    for(int i=1; i<=N; i++){
      vector<bool> used = vector<bool>(N+1);
      bool counted = false;
      for(int j=1; j<=N; j++){
        cin >> a[i][j];
        if (i == j) trace += a[i][j];
        if(used[a[i][j]] == true && !counted){
          row++;
          counted = true;
        }
        used[a[i][j]] = true;
      }
    }
    for(int j=1; j<=N; j++){
      vector<bool> used = vector<bool>(N+1);
      bool counted = false;
      for(int i=1; i<=N; i++){
        if(used[a[i][j]] == true && !counted){
          col++;
          counted = true;
        }
        used[a[i][j]] = true;
      }
    }
    cout << "Case #" << t << ": " << trace << " " << row << " " << col << endl;
  }
  return 0;
}
