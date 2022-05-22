#include<bits/stdc++.h>
using namespace std;

int main () {
  int n, m;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<int> inedges(n);
  for(int i=0; i<m; i++) {
    int l;
    cin >> l;
    int h, t;
    cin >> h;
    for(int j=1; j<l; j++) {
      cin >> t;
      graph[h-1].push_back(t-1);
      inedges[t-1]++;
      h = t;
    }
  }
  vector<int> ord;
  queue<int> cand;
  int printed_cnt = 0;
  for(int i=0; i<n; i++) {
    if (inedges[i] == 0)
      cand.push(i);
  }
  while(!cand.empty()) {
    int next = cand.front();
    cand.pop();
    ord.push_back(next + 1);
    printed_cnt++;
    for(auto t: graph[next]) {
      inedges[t]--;
      if (inedges[t] == 0) {
        cand.push(t);
      }
    }
  }
  if (printed_cnt < n) {
    cout << "0\n";
    return 0;
  }
  for(int i=0; i<n; i++)
    cout << ord[i] << '\n';
  return 0;
}
