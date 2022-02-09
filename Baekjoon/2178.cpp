#include<iostream>
#include<array>
#include<string>
#include<queue>

using namespace std;
using pii = pair<int, int>;
array<string, 100> maze;
array<array<int, 100>, 100> visited;

int bfs(int n, int m) {
  visited[0][0] = 1;
  queue<pii> q;
  q.push({0, 0});
  while(q.front() != pii{n - 1, m - 1}) {
    pii cur = q.front();
    q.pop();
    if (cur.first + 1 < n && maze[cur.first + 1][cur.second] == '1' && visited[cur.first + 1][cur.second] == 0) {
      visited[cur.first + 1][cur.second] = visited[cur.first][cur.second] + 1;
      q.push({cur.first + 1, cur.second});
    }
    if (cur.first > 0 && maze[cur.first - 1][cur.second] == '1' && visited[cur.first - 1][cur.second] == 0) {
      visited[cur.first - 1][cur.second] = visited[cur.first][cur.second] + 1;
      q.push({cur.first - 1, cur.second});
    }
    if (cur.second + 1 < m && maze[cur.first][cur.second + 1] == '1' && visited[cur.first][cur.second + 1] == 0) {
      visited[cur.first][cur.second + 1] = visited[cur.first][cur.second] + 1;
      q.push({cur.first, cur.second + 1});
    }
    if (cur.second > 0 && maze[cur.first][cur.second - 1] == '1' && visited[cur.first][cur.second - 1] == 0) {
      visited[cur.first][cur.second - 1] = visited[cur.first][cur.second] + 1;
      q.push({cur.first, cur.second - 1});
    }
  }
  return visited[n - 1][m - 1];
}

int main () {
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> maze[i];
  int len = bfs(n, m);
  cout << len << endl;
  return 0;
}
