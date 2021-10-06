#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
/* A. A, B, F. A to B: go to adj cell by 1 step, visiting the cell F is forbidden(obstacle). */

int abss(int a, int b){
  return (a > b ? a - b : b - a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n;
    cin >> t;
    for(int T=0; T<t; T++){
      int pts[3][2];
      for(int i=0; i<3; i++){
        cin >> pts[i][0] >> pts[i][1];
      }
      int absx = abss(pts[0][0], pts[1][0]), absy = abss(pts[0][1], pts[1][1]);
      if (pts[0][0] != pts[1][0] && pts[0][1] != pts[1][1]) {
        cout << absx + absy << endl;
      } else if (pts[0][0] == pts[1][0]){
        if (pts[2][0] == pts[0][0] &&
            ((pts[0][1] > pts[2][1] && pts[1][1] < pts[2][1]) || (pts[0][1] < pts[2][1] && pts[1][1] > pts[2][1]))) {
          cout << absx + absy + 2 << endl;
        } else cout << absx + absy << endl;
      } else if (pts[0][1] == pts[1][1]){
        if (pts[2][1] == pts[0][1] &&
            ((pts[0][0] > pts[2][0] && pts[1][0] < pts[2][0]) || (pts[0][0] < pts[2][0] && pts[1][0] > pts[2][0]))) {
          cout << absx + absy + 2 << endl;
        } else cout << absx + absy << endl;
      }
    }
    return 0;
}
