#include<map>
#include<vector>
#include<iostream>
using namespace std;

int defected_bfs(map<int, vector<int>> &connections, vector<bool> &visited, int start) {
  int count = 0;
  if (visited[start]) return 0;
  visited[start] = true;
  for(int i=0; i<connections[start].size(); i++) {
    count += defected_bfs(connections, visited, connections[start][i]);
  }
  return count + 1;
}

int main () {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> connections;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    connections[a].push_back(b);
    connections[b].push_back(a);
  }
  vector<bool> visited(n+1, false);
  int count = defected_bfs(connections, visited, 1);
  cout << count - 1 << endl; // 1 is the root; already infected
  return 0;
}
