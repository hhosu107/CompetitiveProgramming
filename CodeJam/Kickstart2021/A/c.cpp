#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* C. Rabbit house
 * R*C grid rabbit house
 * Rabiit jumps: stacked several boxes on several cells of the grid.
 * Dangerous for the rabbit to make jumps of height > 1 box. Adjust this:
 * For every pair of adjacent cells, absolute difference must be at most 1.
 * As all the boxes are superglued, cannot remove box from the initial statement.
 * So, add boxes as she wants.
 * Compute the minimum total number of boxes to be added.
 *
 * Sol: make a 45-degreed pyramid for each local maxima. Then can I compute the number of added boxes efficiently? I mean, in time complexity O(RCi?
 *
 *
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
