#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &x: a)
    cin >> x;
  sort(a.rbegin(), a.rend());
  ll max_weight = 0;
  for(int i=0; i<n; i++) {
    if (max_weight < (i + 1) * a[i])
      max_weight = (i + 1) * a[i];
  }
  cout << max_weight << '\n';
  return 0;
}
