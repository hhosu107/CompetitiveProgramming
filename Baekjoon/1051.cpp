#include<bits/stdc++.h>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;
  vector<string> digits(n);
  int maxlen = 1;
  for(int i=0; i<n; i++)
    cin >> digits[i];
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<m-1; j++) {
      for(int l=1; l+i<n && l+j<m; l++) {
        if (digits[i][j] == digits[i+l][j] && digits[i][j] == digits[i][j+l] && digits[i][j] == digits[i+l][j+l]) {
          maxlen = max(maxlen, l+1);
        }
      }
    }
  }
  cout << maxlen * maxlen << endl;
  return 0;
}
