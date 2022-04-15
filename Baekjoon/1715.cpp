#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  int l;
  for(int i=0; i<n; i++) {
    cin >> l;
    pq.push(l);
  }
  ll comp_cnt = 0;
  while(n > 1) {
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();
    pq.push(a + b);
    comp_cnt += (a + b);
    n--;
  }
  cout << comp_cnt << '\n';
  return 0;
}
