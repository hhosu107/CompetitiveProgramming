#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<array>
#include<vector>
using namespace std;

using pii = pair<int, int>;
array<string, 25> maze;
array<array<int, 25>, 25> visited;

vector<int> dfs_sizes(int n) {
  vector<int> sizes = vector<int>();
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if (visited[i][j]) continue;
      else if (maze[i][j] == '1'){
        visited[i][j] = 1;
        stack<pii> connected = stack<pii>();
        int connected_size = 0;
        connected.push({i, j});
        while(!connected.empty()) {
          pii top = connected.top();
          if (top.first + 1 < n && maze[top.first + 1][top.second] == '1' && visited[top.first + 1][top.second] == 0) {
            visited[top.first + 1][top.second] = 1;
            connected.push({top.first + 1, top.second});
            continue;
          }
          if (top.first > 0 && maze[top.first - 1][top.second] == '1' && visited[top.first - 1][top.second] == 0) {
            visited[top.first - 1][top.second] = 1;
            connected.push({top.first - 1, top.second});
            continue;
          }
          if (top.second + 1 < n && maze[top.first][top.second + 1] == '1' && visited[top.first][top.second + 1] == 0) {
            visited[top.first][top.second + 1] = 1;
            connected.push({top.first, top.second + 1});
            continue;
          }
          if (top.second > 0 && maze[top.first][top.second - 1] == '1' && visited[top.first][top.second - 1] == 0) {
            visited[top.first][top.second - 1] = 1;
            connected.push({top.first, top.second - 1});
            continue;
          }
          connected_size += 1;
          connected.pop();
        }
        sizes.push_back(connected_size);
      }
    }
  }
  sort(sizes.begin(), sizes.end());
  return sizes;
}

int main () {
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> maze[i];
  }
  vector<int> sizes = dfs_sizes(n);
  cout << sizes.size() << endl;
  for(int i=0; i<sizes.size(); i++)
    cout << sizes[i] << endl;
  return 0;
}
