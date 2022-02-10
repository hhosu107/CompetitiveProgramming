#include<iostream>
#include<vector>
using namespace std;

#define ll long long

int main () {
  int n, m;
  ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  cin >> n >> m;
  ll a[100000], psum[100001];
  for(int i=0; i<n; i++) {
    cin >> a[i];
    psum[i+1] = psum[i] + a[i];
  }
  int l, r;
  for(int i=0; i<m; i++) {
    cin >> l >> r;
    cout << psum[r] - psum[l-1] << '\n';
  }
  return 0;
}
