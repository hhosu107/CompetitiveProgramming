#include<bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> b(n);
    for(int i=0; i<(n/2) + (n%2); i++) {
      b[i] = a[2 * i];
    }
    for(int i=n/2 + (n%2); i<n; i++) {
      b[i] = a[2 * n - 1 -2*i];
    }
    int diffmax = abs(b[0] - b[n-1]);
    for(int i=0; i<n-1; i++)
      diffmax = max(diffmax, abs(b[i] - b[i+1]));
    cout << diffmax << '\n';
  }
  return 0;
}
