#include<bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> modi(n, false);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "YES" << '\n';
      continue;
    }
    bool correct = true;
    for(int i=0; i<n-1; i++) {
      if (a[i] > a[i + 1]) {
        // Case 1: decrease a[i]: try this first
        // case 2: increase a[i + 1] : try this last
        if (modi[i] == false && n + 1 - a[i] <= a[i + 1] && (i == 0 || (n + 1 - a[i] >= a[i-1]))) {
          a[i] = n + 1 - a[i];
          modi[i] = true;
        } else if (n + 1 - a[i + 1] >= a[i]) {
          a[i + 1] = n + 1 - a[i + 1];
          modi[i + 1] = true;
        } else {
          correct = false;
          cout << "NO\n";
          break;
        }
      }
    }
    if (correct) {
      cout << "YES\n";
    }
  }
  return 0;
}
