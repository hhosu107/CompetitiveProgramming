#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
vector<vector<ll>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  v = vector<vector<ll>>(100001, vector<ll>(3, 0));
  ll denom = 1000000009L;
  v[1][0] = 1;
  v[2][1] = 1;
  v[3][0] = 1;
  v[3][1] = 1;
  v[3][2] = 1;
  for(int i=4; i<=100000; i++) {
    for(int j=0; j<3; j++) {
      v[i][j] = (v[i-(j+1)][(j+1)%3] + v[i-(j+1)][(j+2)%3]) % denom;
    }
  }
  for(int i=0; i<t; i++) {
    int n;
    cin >> n;
    cout << (v[n][0] + v[n][1] + v[n][2]) % denom << '\n';
  }
}
