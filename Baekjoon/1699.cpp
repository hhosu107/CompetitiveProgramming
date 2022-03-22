#include<bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> v = vector<int>(n+1, 100);
  v[0] = 0;
  for(int i=1; i<=n; i++) {
    for(int j=1; j*j <= i; j++) {
      if (v[i-j*j] < 100)
        v[i] = min(v[i], v[i-j*j] + 1);
    }
  }
  cout << v[n] << endl;
  return 0;
}
