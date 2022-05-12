#include<bits/stdc++.h>
using namespace std;

vector<int> is_cycle;

int dfs(int start, int path_len, map<int, int> &cycle, map<int, int> &graph) {
  int next_node = graph[start];
  if (is_cycle[next_node] != -1) {
    is_cycle[start] = 0;
    return 0;
  }
  if (cycle.find(next_node) != cycle.end()) {
    is_cycle[start] = 1;
    return cycle[next_node]; // cycle에 들어간 몇 번째 element부터 진짜 cycle인가
  }
  cycle[next_node] = path_len;
  int result = dfs(next_node, path_len + 1, cycle, graph);
  if (result < path_len) { // cycle 안쪽
    is_cycle[start] = 1;
  } else { // cycle 바깥쪽
    is_cycle[start] = 0;
  }
  return result;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> pt(n);
    int arr;
    map<int, int> graph;
    for(int i=0; i<n; i++) {
      cin >> arr;
      graph[i] = arr - 1;
    }
    is_cycle = vector<int>(n, -1);
    for(int i=0; i<n; i++) {
      map<int, int> cycle;
      cycle[i] = 0;
      if (is_cycle[i] != -1) continue;
      dfs(i, 1, cycle, graph);
    }
    int sum = 0;
    for(int i=0; i<n; i++)
      sum += is_cycle[i];
    cout << n - sum << '\n';
  }
  return 0;
}
