/* 11049.
 * M1, .., Mn: matrices with R_i * C_i shape.
 * Matmul requires R_i * C_i * C_j operations.
 * Minimize the sum of operations.
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int _INT_MAX = 2147483647;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  int N, K;
  cin >> N;
  vector<vector<int>> shapes = vector<vector<int>>(N + 1, vector<int>(2));
  for(int i=0; i<N; i++){
    cin >> shapes[i + 1][0] >> shapes[i + 1][1];
  }
  vector<vector<int>> operations = vector<vector<int>>(N+1, vector<int>(N+1));
  for(int d = 1; d < N; d++){
    for(int i = 1; i + d <= N; i++){
      int j = i + d;
      operations[i][j] = _INT_MAX;
      for(int mid = i; mid < j; mid++){
        operations[i][j] = min(operations[i][j], operations[i][mid] + operations[mid+1][j] + shapes[i][0] * shapes[mid][1] * shapes[j][1]);
      }
    }
  }
  cout << operations[1][N] << '\n';
  return 0;
}
