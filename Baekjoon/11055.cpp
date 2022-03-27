#include<bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto& i: a) cin >> i;
  vector<int> subsum(n);
  subsum[0] = a[0];
  int maxsubsum = subsum[0];
  for(int i=1; i<n; i++) {
    subsum[i] = a[i];
    for(int j=0; j<i; j++) {
      if (a[j] < a[i])
        subsum[i] = max(subsum[i], subsum[j] + a[i]);
    }
    maxsubsum = max(maxsubsum, subsum[i]);
  }
  cout << maxsubsum << '\n';
  return 0;
}
