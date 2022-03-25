#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];
  int start, end;
  cin >> start >> end;
  start--;
  end--;
  vector<bool> visited(n, false);
  visited[start] = true;
  queue<pii> q;
  q.push({start, 0});
  bool reachable = false;
  while(!q.empty()) {
    pii cur = q.front();
    q.pop();
    if(cur.first == end) {
      reachable = true;
      cout << cur.second << '\n';
      break;
    }
    int step_base = a[cur.first];
    for(int i=cur.first - step_base; i >= 0; i -= step_base) {
      if(!visited[i]) {
        visited[i] = true;
        q.push({i, cur.second + 1});
      }
    }
    for(int i=cur.first + step_base; i<n; i += step_base) {
      if(!visited[i]) {
        visited[i] = true;
        q.push({i, cur.second + 1});
      }
    }
  }
  if(!reachable) cout << "-1\n";
  return 0;
}
