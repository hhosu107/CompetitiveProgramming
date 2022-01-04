#include<iostream>
#include<array>
#include<queue>

using namespace std;
using mat=array<array<int, 50>, 50>;

int findscc(mat &visited, int m, int n) {
  int cnt = 0;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(visited[i][j] == 0) {
        cnt++;
        queue<int> x, y;
        x.push(i);
        y.push(j);
        visited[i][j] = 1;
        while(!x.empty()) {
          int cx = x.front();
          x.pop();
          int cy = y.front();
          y.pop();
          if (cx > 0 && visited[cx - 1][cy] == 0) {
            visited[cx - 1][cy] = 1;
            x.push(cx - 1);
            y.push(cy);
          }
          if(cx < m - 1 && visited[cx + 1][cy] == 0) {
            visited[cx + 1][cy] = 1;
            x.push(cx + 1);
            y.push(cy);
          }
          if(cy > 0 && visited[cx][cy - 1] == 0) {
            visited[cx][cy - 1] = 1;
            x.push(cx);
            y.push(cy - 1);
          }
          if(cy < n - 1 && visited[cx][cy + 1] == 0) {
            visited[cx][cy + 1] = 1;
            x.push(cx);
            y.push(cy + 1);
          }
        }
      }
    }
  }
  return cnt;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m, n;
  int k;
  int t;
  int x, y;
  cin >> t;
  for(int T=0; T<t; T++){
    cin >> m >> n >> k;
    mat yard{};
    for(int i=0; i<k; i++){
      cin >> x >> y;
      yard[x][y] = 1;
    }
    mat searched{};
    for(int i=0; i<50; i++){
      for(int j=0; j<50; j++){
        searched[i][j] = 1 - yard[i][j];
      }
    }
    int scc = findscc(searched, m, n);
    cout << scc << endl;
  }
  return 0;
}
