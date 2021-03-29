#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * B. L shaped plots
 * Grid R*C, filled with 0 or 1.
 * A segment is a nonempty seq of consecutive cells such that all cells are in the same row/same column. Length of a segment = # cells in the seq.
 * Good segment: a segment only filled with 1s.
 * L-shape: defined as an "UNORDERED" pair of segments (doesn't have an order between horizontal/vertical segments)
 * - Each of the segments must be a good segment.
 * - The two segments must be perpendicular.
 * - The two segments must share one cell that is an endpoint of both segments.
 * - Both segments must have length at least 2.
 * - The length of the longer segment is "twice" the length of the shorter segment.
 *
 * Count the number of L-shapes in the grid.
 */

/* Sol: Can I count this?
 * At point i, j: calculate 4 lengths: (i, j), (i-1, j), .., (i-k, j) | (i, j), (i, j+1), ..., (i, j+k), ... in the amortized time complexity O(1)?
 * Maybe possible:
 * for i from 0 to R-1 :
 *     j = 0
 *     while j < C:
 *     if cell[i][j] == 1:
 *        increase k until cell[i][j+k] != 0 or j + k == C
 *        fill cell[i][j~j+k-1]'s left length as 1 ~ k, right length as k ~ 1.
 *        increase j by k
 * for j from 0 to C-1: vice versa
 *
 * for i from 0 to R-1: for j from 0 to C-1:
 * compute 4 possible L shapes.
 */

int mini(int a, int b){
  return (a < b) ? a : b;
}

int maxi(int a, int b){
  return (a > b) ? a : b;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  string ss;
  int T, R, C;
  cin >> T;
  for (int t=1; t<=T; t++){
    cin >> R >> C;
    vector<vector<int>> cell = vector<vector<int>>(R, vector<int>(C));
    vector<vector<vector<int>>> lengths = vector<vector<vector<int>>>(R, vector<vector<int>>(C, vector<int>(4)));
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        cin >> cell[i][j];
      }
    }
    for(int i=0; i<R; i++){
      int j=0;
      while (j < C){
        int k=1;
        if(cell[i][j] == 1){
          while(j + k < C && cell[i][j+k] == 1){
            k++;
          }
          for(int x=j; x<j+k; x++){
            lengths[i][x][0] = x - j + 1;
            lengths[i][x][2] = k - (x - j);
          }
        }
        j += k;
      }
    }
    for(int j=0; j<C; j++){
      int i=0;
      while (i < R){
        int k=1;
        if(cell[i][j] == 1){
          while(i + k < R && cell[i+k][j] == 1){
            k++;
          }
          for(int x=i; x<i+k; x++){
            lengths[x][j][1] = x - i + 1;
            lengths[x][j][3] = k - (x - i);
          }
        }
        i += k;
      }
    }
    int count = 0;
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        for(int k=0; k<4; k++){
          int l1 = maxi(mini(lengths[i][j][k] - 1, (lengths[i][j][(k+1)%4] - 2) / 2), 0);
          int l2 = maxi(mini(lengths[i][j][(k+1)%4] - 1, (lengths[i][j][k] - 2) / 2), 0);
          count += (l1 + l2);
        }
      }
    }
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
