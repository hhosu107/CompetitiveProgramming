#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(vector<string> &plate, vector<vector<bool>> &visited, vector<bool> &a_used, int x, int y, int n, int m, int cnt) {
  int ret = cnt + 1;
  visited[x][y] = true;
  a_used[(int)(plate[x][y] - 'A')] = true;
  for(int i=0; i<4; i++) {
    int nx = x + dd[i][0];
    int ny = y + dd[i][1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (visited[nx][ny]) continue;
    if (a_used[(int)(plate[nx][ny] - 'A')]) continue;
    a_used[(int)(plate[nx][ny] - 'A')] = true;
    int tmp = dfs(plate, visited, a_used, nx, ny, n, m, cnt + 1);
    ret = max(ret, tmp);
    a_used[(int)(plate[nx][ny] - 'A')] = false;
  }
  visited[x][y] = false;
  return ret;
}

int main () {
  int R, C;
  cin >> R >> C;
  vector<string> plate(R);
  for(auto &r: plate) cin >> r;
  vector<vector<bool>> visited(R, vector<bool>(C, false));
  vector<bool> a_used(26, false);
  int len = dfs(plate, visited, a_used, 0, 0, R, C, 0);
  cout << len << endl;
  return 0;
}
