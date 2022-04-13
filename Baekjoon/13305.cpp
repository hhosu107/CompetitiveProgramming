#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> dist(n-1, 0);
  vector<ll> val(n, 0);
  for(int i=0; i<n-1; i++)
    cin >> dist[i];
  for(int i=0; i<n; i++)
    cin >> val[i];
  ll sum = 0;
  ll local_min = val[0];
  for(int i=0; i<n-1; i++) {
    sum += dist[i] * local_min;
    local_min = min(local_min, val[i + 1]);
  }
  cout << sum << '\n';
  return 0;
}
