#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<array>

using namespace std;

array<array<int, 100>, 100> valid;
array<int, 100> visited;

void bfs(int i, map<int, vector<int>> &edges) {
  queue<int> q;
  vector<int> v;
  q.push(i);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int x: edges[cur]) {
      if (valid[i][x] == 0) {
        edges[i][x] = 1;
        valid[i][x] = 1;
        q.push(x);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  map<int, vector<int>> edges;
  int is_edge;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> is_edge;
      if(is_edge) {
        edges[i].push_back(j);
        edges[j].push_back(i);
      }
    }
  }
  for(int i=0; i<n; i++) {
    bfs(i, edges);
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << valid[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
