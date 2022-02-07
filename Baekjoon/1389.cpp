#include<map>
#include<array>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs(int start, map<int, vector<int>> &connections) {
  queue<int> q;
  q.push(start);
  array<int, 101> visited = array<int, 101>();
  array<int, 101> distance = array<int, 101>();
  visited[start] = 1;
  distance[start] = 0;
  int distance_sum = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < connections[cur].size(); i++) {
      int next = connections[cur][i];
      if (visited[next] == 0) {
        visited[next] = 1;
        distance[next] = distance[cur] + 1;
        distance_sum += distance[next];
        q.push(next);
      }
    }
  }
  return distance_sum;
}

int main () {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> connections;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    connections[a].push_back(b);
    connections[b].push_back(a);
  }
  int bacon = 10101;
  int baconperson = -1;
  for(int i=1; i<=n; i++){
    int dist = bfs(i, connections);
    baconperson = (bacon > dist ? i : baconperson);
    bacon = min(bacon, dist);
  }
  cout << baconperson << endl;
  return 0;
}
