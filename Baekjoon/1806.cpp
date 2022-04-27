#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, s;
  cin >> n >> s;
  vector<ll> nums(n);
  for(auto &x: nums) cin >> x;
  int l = 0, r = 0;
  int minlen = n + 1;
  ll cursum = 0;
  while(r < n) {
    while(cursum < s && r < n) {
      cursum += nums[r];
      r++;
    }
    while(cursum >= s) {
      cursum -= nums[l];
      l++;
      minlen = min(minlen, r - l + 1);
    }
  }
  cout << (minlen >= n + 1 ? 0 : minlen) << '\n';
  return 0;
}
