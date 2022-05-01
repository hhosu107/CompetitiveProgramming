#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
using ll = long long;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, n, m;
  cin >> t;
  cin >> n;
  vector<ll> a(n), pa(n+1);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    pa[i+1] = pa[i] + a[i];
  }
  cin >> m;
  vector<ll> b(m), pb(m+1);
  for(int i=0; i<m; i++) {
    cin >> b[i];
    pb[i+1] = pb[i] + b[i];
  }
  vector<ll> a_partial((n+1)*n/2);
  int cnt = 0;
  for(int i=0; i<n; i++) {
    ll p_sum = 0;
    for(int j=0; j<=i; j++) {
      p_sum += a[j];
    }
    a_partial[cnt++] = p_sum;
    for(int j=i+1; j<n; j++) {
      p_sum += a[j];
      p_sum -= a[j-i-1];
      a_partial[cnt++] = p_sum;
    }
  }
  unordered_map<ll, int> b_partial_map = unordered_map<ll, int>();
  for(int i=0; i<m; i++) {
    ll p_sum = 0;
    for(int j=0; j<=i; j++) {
      p_sum += b[j];
    }
    if (b_partial_map.find(p_sum) == b_partial_map.end()) {
      b_partial_map[p_sum] = 1;
    }
    else b_partial_map[p_sum] += 1;
    for(int j=i+1; j<m; j++) {
      p_sum += b[j];
      p_sum -= b[j-i-1];
      if (b_partial_map.find(p_sum) == b_partial_map.end()) {
        b_partial_map[p_sum] = 1;
      }
      else b_partial_map[p_sum] += 1;
    }
  }
  ll ans = 0;
  for(int i=0; i<n*(n+1)/2; i++) {
    ans += b_partial_map[t-a_partial[i]];
  }
  cout << ans << '\n';
  return 0;
}
