#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

using ll = long long;
int main () {
  int n;
  cin >> n;
  vector<vector<ll>> bino(71, vector<ll>(71, 0));
  bino[0][0] = bino[1][0] = bino[1][1] = 1;
  for(int i=2; i<=2*n; i++) {
    for(int j=0; j<=i; j++) {
      bino[i][j] = bino[i-1][j] + (j > 0 ? bino[i-1][j-1] : 0);
    }
  }
  cout << bino[2*n][n] / (n + 1) << endl;
  return 0;
}
