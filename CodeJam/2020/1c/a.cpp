#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;

/* A
 * infinitely long streets from N-S, W-E
 * : (n, m) for n, m in integer
 * Goal: To be at oine of the intersectinos on Peppurr's tour at the same time that Peppurr is there.
 * And do so as fast as possible.
 * Peppurr starts at (X, Y) where I am (0, 0).
 * Peppurr walks to predefined path.
 * I can take a picture at the exact "Intersection".
 * I can standstill or walk to any 4 directions.
 * Can I take? If possiuble, how soon?
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  int X, Y;
  string path;
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> X >> Y >> path;
    cout << "Case #" << t << ": ";
    if (X + Y == 0){
      cout << 0 << endl;
      continue;
    }
    bool met = false;
    for(int i=0; i<path.size(); i++){
      switch(path[i]){
        case 'E':
          X++;
          break;
        case 'W':
          X--;
          break;
        case 'N':
          Y++;
          break;
        case 'S':
          Y--;
          break;
      }
      int len = (X > 0 ? X : -X) + (Y > 0 ? Y : -Y);
      if (len <= i+1){
        met = true;
        cout << i + 1 << endl;
        break;
      }
    }
    if(!met) cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
