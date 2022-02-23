#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int convert_bfs(ll a, ll b) {
  queue<pll> q;
  q.push({a, 0});
  while(!q.empty()) {
    pll cur = q.front();
    q.pop();
    if (cur.first == b) return cur.second + 1;
    if (cur.first * 2 <= b) q.push({cur.first * 2, cur.second + 1});
    if (cur.first * 10 + 1 <= b) q.push({cur.first * 10 + 1, cur.second + 1});
  }
  return -1;
}

int main () {
  int a, b;
  cin >> a >> b;
  cout << convert_bfs(a, b) << endl;
  return 0;
}
