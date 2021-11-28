#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
  int m, n;
  char chess[51][51];
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  char wchess[9][9];
  char bchess[9][9];
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if ((i + j) % 2 == 0) {
        wchess[i][j] = 'W';
        bchess[i][j] = 'B';
      }
      else {
        wchess[i][j] = 'B';
        bchess[i][j] = 'W';
      }
    }
  }

  cin >> m >> n;
  int mincheck = 64;
  for (int i=0; i<m; i++)
    cin >> chess[i];
  for(int i=0; i<m-7; i++){
    for(int j=0; j<n-7; j++){
      int wdiff = 0;
      int bdiff = 0;
      for(int k=0; k<8; k++){
        for(int l=0; l<8; l++){
          wdiff += (chess[i+k][j+l] != wchess[k][l] ? 1 : 0);
          bdiff += (chess[i+k][j+l] != bchess[k][l] ? 1 : 0);
        }
      }
      if (mincheck > wdiff) mincheck = wdiff;
      if (mincheck > bdiff) mincheck = bdiff;
    }
  }
  cout << mincheck << '\n';
  return 0;
}
