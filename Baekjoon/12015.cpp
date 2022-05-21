#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// LIS without recovering the original sequence; only length

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> L;
  int lis_idx = 0;
  for(int i=0; i<n; i++) {
    if (lis_idx == 0) {
      L.push_back(a[i]);
      lis_idx++;
    }
    else {
      if (L[lis_idx-1] < a[i]) { // Extends LIS
        L.push_back(a[i]);
        lis_idx++;
      }
      else {
        // Ex. L = [1, 1, 3, 3, 3, 5], a[i] = 2. Then
        // lower_bound(L.begin(), L.end(), a[i])-L.begin() = 2.
        L[lower_bound(L.begin(), L.end(), a[i])-L.begin()] = a[i]; // lower_bound works in O(log(n))
      }
    }
  }
  cout << lis_idx << '\n';
  return 0;
}
