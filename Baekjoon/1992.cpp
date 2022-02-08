#include<iostream>
#include<array>
#include<string>

using namespace std;

array<string, 64> tile;

string quad_str(array<string, 64> &tile, int x, int y, int n) {
  if (n == 1) {
    return string{tile[x][y]};
  } else {
    char a = tile[x][y];
    bool zipable = true;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if (a != tile[x+i][y+j]) {
          zipable = false;
          break;
        }
      }
      if(!zipable) break;
    }
    if (zipable)
      return string{a};
    else {
      return "(" + quad_str(tile, x, y, n/2) + quad_str(tile, x, y + n/2, n / 2) + quad_str(tile, x + n/2, y, n / 2) + quad_str(tile, x + n/2, y + n/2, n / 2) + ")";
    }
  }
}

int main () {
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> tile[i];
  }
  string ans = quad_str(tile, 0, 0, n);
  cout << ans << endl;
  return 0;
}
