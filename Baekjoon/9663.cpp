#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int avail[16][16] = {0};

long long int cnt = 0;
void nqueen_cnt(int q, int n){
  if (q == n) {
    cnt++;
    return;
  }
  for(int i=0; i<n; i++){
    if (avail[q][i] == 0) {
      for(int j=q+1; j<n; j++) {
        avail[j][i] = avail[j][i] + 1;
      }
      for (int j=1; q + j < n && i + j < n; j++)
        avail[q + j][i + j] = avail[q + j][i + j] + 1;
      for(int j = 1; q + j < n && i - j >= 0; j++)
        avail[q + j][i - j] = avail[q + j][i - j] + 1;
      nqueen_cnt(q + 1, n);
      for(int j=q+1; j<n; j++) {
        avail[j][i] = avail[j][i] - 1;
      }
      for (int j=1; q + j < n && i + j < n; j++)
        avail[q + j][i + j] = avail[q + j][i + j] - 1;
      for(int j = 1; q + j < n && i - j >= 0; j++)
        avail[q + j][i - j] = avail[q + j][i - j] - 1;
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<bool>> chess = vector<vector<bool>>(N, vector<bool>(N, true));
  nqueen_cnt(0, N);
  cout << cnt << endl;
  return 0;
}
