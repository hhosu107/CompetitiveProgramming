#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// LIS with recovering the original sequence; only length

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> lis_place(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> L;
  int lis_idx = 0;
  for(int i=0; i<n; i++) {
    if (lis_idx == 0) {
      lis_place[i] = lis_idx;
      L.push_back(a[i]);
      lis_idx++;
    }
    else {
      if (L[lis_idx-1] < a[i]) { // Extends LIS
        lis_place[i] = lis_idx;
        L.push_back(a[i]);
        lis_idx++;
      }
      else {
        // Ex. L = [1, 1, 3, 3, 3, 5], a[i] = 2. Then
        // lower_bound(L.begin(), L.end(), a[i])-L.begin() = 2.
        int curr_lis_place = lower_bound(L.begin(), L.end(), a[i])-L.begin();
        lis_place[i] = curr_lis_place;
        L[curr_lis_place] = a[i]; // lower_bound works in O(log(n))
      }
    }
  }
  cout << lis_idx << '\n';
  vector<int> lis(lis_idx);
  for(int i=n-1; i>=0; i--) {
    if (lis_idx == lis_place[i] + 1) { // From backward to forward, find the latest element that can be placed in lis_idx-1th index in lis.
      lis[lis_idx-1] = a[i];
      lis_idx--;
    }
  }
  for(auto x: lis) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}
