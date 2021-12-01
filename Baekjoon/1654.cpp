#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

bool possible(vector<ll> &exists, ll len, ll n){
  ll cnt = 0;
  for(auto& l: exists)
    cnt += l / len;
  return cnt >= n;
}

int main () {
  ll k, n;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> k >> n;
  vector<ll> exists = vector<ll>(k);
  for(auto& l: exists)
    cin >> l;
  sort(exists.rbegin(), exists.rend());
  ll max = exists[0];
  ll min = 1;
  while(min + 1 < max) {
    ll len = (max + min) / 2;
    bool possib = possible(exists, len, n);
    if (possib) {
      min = len;
    } else max = len - 1;
  }
  if (possible(exists, max, n)) cout << max << '\n';
  else cout << min << '\n';
  return 0;
}
