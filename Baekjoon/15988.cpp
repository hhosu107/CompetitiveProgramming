#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
vector<ll> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  v = vector<ll>(1000001);
  ll denom = 1000000009L;
  v[1] = 1;
  v[2] = 2;
  v[3] = 4;
  for(int i=4; i<=1000000; i++) {
    v[i] = (v[i-1] + v[i-2] + v[i-3]) % 1000000009L;
  }
  for(int i=0; i<t; i++) {
    int n;
    cin >> n;
    cout << v[n] << '\n';
  }
}
