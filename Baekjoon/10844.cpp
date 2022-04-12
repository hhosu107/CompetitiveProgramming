#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<vector<int>> ed(n, vector<int>(10, 0));
  for(int i=1; i<10; i++)
    ed[0][i] = 1;
  for(int i=1; i<n; i++) {
    for(int j=0; j<10; j++) {
      ed[i][j] = ((j > 0 ? ed[i-1][j-1] : 0) + (j < 9 ? ed[i-1][j+1] : 0)) % 1000000000;
    }
  }
  int ans = 0;
  for(int i=0; i<10; i++) {
    ans = (ans + ed[n-1][i]) % 1000000000;
  }
  cout << ans << endl;
  return 0;
}
