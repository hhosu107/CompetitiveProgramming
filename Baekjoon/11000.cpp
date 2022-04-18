#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<pll> acts(n);
  for(auto &a: acts)
    cin >> a.first >> a.second;
  sort(acts.begin(), acts.end());
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  pq.push(acts[0].second);
  for(int i=1; i<n; i++) {
    if (acts[i].first < pq.top()) {
      pq.push(acts[i].second); // If the first activity isn't finished, then since all others that are already in pq are not finished (pq contains end time), we need a new classroom.
    } else {
      pq.pop(); // We pop only once, since we already enlarged the classroom.
      pq.push(acts[i].second);
    }
  }
  cout << pq.size() << endl;
  return 0;
}
