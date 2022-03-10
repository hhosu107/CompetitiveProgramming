#include<bits/stdc++.h>
using namespace std;

int val[2][3];
int maxdp[2][3];
int mindp[2][3];

int MAX = 100000000;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++) {
      cin >> val[i%2][j];
      if (i == 0) {
        maxdp[i%2][j] = mindp[i%2][j] = val[i%2][j];
      } else {
        maxdp[i%2][j] = val[i%2][j] + max(max((j <= 1 ? maxdp[(i+1)%2][0] : 0), (j >= 1 ? maxdp[(i+1)%2][2] : 0)), maxdp[(i+1)%2][1]);
        mindp[i%2][j] = val[i%2][j] + min(min((j <= 1 ? mindp[(i+1)%2][0] : MAX), (j >= 1 ? mindp[(i+1)%2][2] : MAX)), mindp[(i+1)%2][1]);
      }
    }
  }
  cout << max(max(maxdp[(n-1)%2][0], maxdp[(n-1)%2][1]), maxdp[(n-1)%2][2]) << ' ' << min(min(mindp[(n-1)%2][0], mindp[(n-1)%2][1]), mindp[(n-1)%2][2]) << '\n';
  return 0;
}
