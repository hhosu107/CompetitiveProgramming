#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &edges, vector<bool> &visited, vector<int> &knows) {
  for(int x: knows) visited[x] = true;
  queue<int> q;
  for (auto x: knows) q.push(x);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v: edges[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int t;
  cin >> t;
  vector<int> knows(t);
  for(auto &x: knows) cin >> x;
  for_each(knows.begin(), knows.end(), [m](int &x) {x += m;});
  vector<vector<int>> edges(m + n + 1, vector<int>());
  vector<vector<int>> parties(n + 1, vector<int>());
  for(int i=0; i<m; i++) {
    int people;
    cin >> people;
    int person;
    for(int j=0; j<people; j++) {
      cin >> person;
      edges[i].push_back(m + person);
      edges[m + person].push_back(i);
      parties[person].push_back(i);
    }
  }
  vector<bool> visited(m + n + 1, false);
  bfs(edges, visited, knows);
  vector<bool> valid_party(m, true);
  for(int i=m+1; i<=m+n; i++) {
    if (visited[i]) {
      for(int j: parties[i - m]) {
        valid_party[j] = false;
      }
    }
  }
  int count = 0;
  for(int i=0; i<m; i++)
    if (valid_party[i]) count++;
  cout << count << '\n';
  return 0;
}
