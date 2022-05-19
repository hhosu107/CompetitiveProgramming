#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, e;
  cin >> n >> e;
  vector<vector<int>> outedges(n, vector<int>());
  vector<int> count_inedges(n, 0);
  int s, t;
  for(int i=0; i<e; i++) {
    cin >> s >> t;
    outedges[s-1].push_back(t-1);
    count_inedges[t-1]++;
  }
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i=0; i<n; i++) {
    if(count_inedges[i] == 0) {
      pq.push(i);
    }
  }
  vector<int> ans(n);
  int solved_cnt = 0;
  while(!pq.empty()) {
    int p = pq.top();
    pq.pop();
    ans[solved_cnt++] = p + 1;
    for(auto np: outedges[p]) {
      count_inedges[np]--;
      if (count_inedges[np] == 0) {
        pq.push(np);
      }
    }
  }
  for(int i=0; i<n; i++)
    cout << ans[i] << " ";
  cout << '\n';
  return 0;
}
