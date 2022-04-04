#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using pii = pair<int, int>;
using ppi = pair<pii, int>;
bool visited[300][300];
int dxy[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

int bfs(pii start, pii end, int n) {
  queue<ppi> q;
  visited[start.first][start.second] = true;
  q.push({start, 0});
  while(!q.empty()) {
    ppi cur = q.front();
    q.pop();
    if(cur.first == end) return cur.second;
    for(int i = 0; i < 8; i++) {
      int nx = cur.first.first + dxy[i][0];
      int ny = cur.first.second + dxy[i][1];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(visited[nx][ny]) continue;
      visited[nx][ny] = true;
      q.push({{nx, ny}, cur.second + 1});
    }
  }
  return -1;
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
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++)
        visited[i][j] = false;
    }
    pii start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    int len = bfs(start, end, n);
    cout << len << '\n';
  }
  return 0;
}
