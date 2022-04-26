#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int plates(vector<string> &grid, int n, int m) {
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int plate = 0;
  for(int i=0; i<n; i++) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(!visited[i][j]) {
          plate++;
          visited[i][j] = true;
          if (grid[i][j] == '|') {
            for(int k=i+1; k<n; k++) {
              if (grid[k][j] != '|')
                break;
              visited[k][j] = true;
            }
          } else if (grid[i][j] == '-') {
            for(int k=j+1; k<m; k++) {
              if (grid[i][k] != '-')
                break;
              visited[i][k] = true;
            }
          }
        }
      }
    }
  }
  return plate;
}

int main () {
  int n, m;
  cin >> n >> m;
  vector<string> pat(n);
  for(auto &p: pat) cin >> p;
  cout << plates(pat, n, m) << endl;
  return 0;
}
