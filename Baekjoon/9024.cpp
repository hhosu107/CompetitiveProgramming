#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  int t;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    int cnt = 0;
    int diff = 2147483647;
    while(l < r) {
      int temp = a[l] + a[r];
      temp = abs(temp - k);
      if (temp < diff) {
        diff = temp;
        cnt = 1;
      } else if (temp == diff) {
        cnt++;
      }
      if (a[l] + a[r] <= k) {
        l++;
      }
      else {
        r--;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
