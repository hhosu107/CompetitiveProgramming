#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;

int dd[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, pii point, int height) {
  visited[point.first][point.second] = 1;
  for(int i=0; i<4; i++) {
    int nx = point.first + dd[i][0];
    int ny = point.second + dd[i][1];
    if (nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size()) continue;
    if (graph[nx][ny] > height && visited[nx][ny] == 0) {
      dfs(graph, visited, {nx, ny}, height);
    }
  }
}

int scc_height(vector<vector<int>> &graph, int height) {
  vector<vector<int>> visited(graph.size(), vector<int>(graph[0].size(), 0));
  int cnt = 0;
  for(int i=0; i<graph.size(); i++) {
    for(int j=0; j<graph.size(); j++) {
      if (graph[i][j] > height && visited[i][j] == 0) {
        cnt++;
        dfs(graph, visited, {i, j}, height);
      }
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n, vector<int>(n, 0));
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> graph[i][j];
  int max_cnt = 0;
  for(int i=0; i<=100; i++) {
    int cnt = scc_height(graph, i);
    max_cnt = max(max_cnt, cnt);
  }
  cout << max_cnt << endl;
  return 0;
}
