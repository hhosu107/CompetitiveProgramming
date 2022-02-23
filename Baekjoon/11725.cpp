#include<bits/stdc++.h>
using namespace std;

vector<int> tree_bfs(map<int, vector<int>> &adj, int size) {
  queue<int> q;
  vector<int> root(size + 1, -1);
  root[1] = 1;
  q.push(1);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v : adj[u]) {
      if(root[v] == -1) {
        root[v] = u;
        q.push(v);
      }
    }
  }
  return root;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int a, b;
  map<int, vector<int>> adj;
  for(int i=0; i<n-1; i++) {
    cin >> a >> b;
    if (adj.find(a) == adj.end()) {
      adj[a] = vector<int>(1, b);
    } else adj[a].push_back(b);
    if (adj.find(b) == adj.end()) {
      adj[b] = vector<int>(1, a);
    } else adj[b].push_back(a);
  }
  vector<int> roots = tree_bfs(adj, n);
  for(int i=2; i<=n; i++)
    cout << roots[i] << '\n';
  return 0;
}
