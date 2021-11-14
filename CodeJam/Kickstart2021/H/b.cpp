#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
 * B. Red+Yellow = Orange, Red+Blue=Purple,
 * Yellow+Blue=Green,Red+Yellow+Blue=Gray
 * proportion/order of each color in the comb doe not matter.
 * R+Y=Y+R=R+Y+R.
 * 1-dim painting P of len N (n squares).
 * P_i : color of ith. Initially P_i = Uncolored.
 * In a single stroke, choose one of three primary colors and apply on a
 * consecutive squares ([l, r]).
 * If a color goes on the uncolored square, it becomes that color. Otherwise,
 * mixed color described above will appear.
 * Compute fewest stroke to generate the aim.
 * Sol) Decompose every color; Then paint with primary colors per each primary
 * segment.
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int len;
    string p;
    cin >> len >> p;
    vector<vector<int>> cols = vector<vector<int>>(3, vector<int>(len));
    for(int i=0; i<len; i++){
      if (p[i] == 'R' || p[i] == 'O' || p[i] == 'P' || p[i] == 'A') cols[0][i] = 1;
      if (p[i] == 'B' || p[i] == 'P' || p[i] == 'G' || p[i] == 'A') cols[1][i] = 1;
      if (p[i] == 'Y' || p[i] == 'O' || p[i] == 'G' || p[i] == 'A') cols[2][i] = 1;
    }
    int segments = 0;
    for(int i=0; i<3; i++){
      bool segment = false;
      for(int j=0; j<len; j++){
        if (cols[i][j] == 1) {
          segment = true;
        } else if (cols[i][j] == 0 && segment == true) {
          segment = false;
          segments += 1;
        }
      }
      if (segment) {
        segments += 1;
      }
    }
    cout << "Case #" << t << ": " << segments << '\n';
  }

  return 0;
}
