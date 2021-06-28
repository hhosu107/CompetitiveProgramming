#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int nqueen_cnt(vector<vector<bool>> &avail, int q, int n){
  long long int curr_cnt = 0L;
  for(int i=0; i<n; i++){
    if (avail[q][i]) {
      if (q + 1 == n) curr_cnt += 1L;
      else {
        vector<vector<bool>> next_chess (avail);
        next_chess[q][i] = false;
        // vertical / horizontal
        for(int j=0; j<n; j++){
          next_chess[q][j] = false;
          next_chess[j][i] = false;
        }
        // diagonals
        for(int j = 1; q + j < n && i + j < n; j++)
          next_chess[q + j][i + j] = false;
        for(int j = 1; q - j >= 0 && i + j < n; j++)
          next_chess[q - j][i + j] = false;
        for(int j = 1; q - j >= 0 && i - j >= 0; j++)
          next_chess[q - j][i - j] = false;
        for(int j = 1; q + j < n && i - j >= 0; j++)
          next_chess[q + j][i - j] = false;
        curr_cnt += nqueen_cnt(next_chess, q + 1, n);
      }
    }
  }
  return curr_cnt;
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<bool>> chess = vector<vector<bool>>(N, vector<bool>(N, true));
  cout << nqueen_cnt(chess, 0, N) << '\n';
  return 0;
}
