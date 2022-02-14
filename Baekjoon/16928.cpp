#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;

int bfs(int start, map<int, vector<int>> roll, map<int, int> upstair, map<int, int> downstair) {
  deque<pii> q;
  int visited[101] = {0};
  for(int i=1; i<=100; i++) {
    visited[i] = 101;
  }
  visited[1] = 0;
  q.push_back({0, start});
  pii top = q.front();
  while(top.second != 100) {
    q.pop_front();
    for(auto i: roll[top.second]) {
      if (downstair.find(i) != downstair.end()) {
        int aim = downstair[i];
        if (visited[aim] == 101 || visited[aim] > top.first + 1) {
          q.push_back({top.first + 1, aim});
          visited[aim] = top.first + 1;
        }
      } else if (upstair.find(i) != upstair.end()) {
        int aim = upstair[i];
        if (visited[aim] == 101 || visited[aim] > top.first + 1) {
          q.push_back({top.first + 1, aim});
          visited[aim] = top.first + 1;
        }
      } else {
        if (visited[i] == 101 || visited[i] > top.first + 1) {
          q.push_back({top.first + 1, i});
          visited[i] = top.first + 1;
        }
      }
    }
    top = q.front();
  }
  return visited[100];
}

int main () {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> roll;
  for(int i=1; i<=99; i++) {
    for(int j=i+1; j<=min(i+6, 100); j++)
      roll[i].push_back(j);
  }
  map<int, int> upstair;
  map<int, int> downstair;
  int start, end;
  for(int i=0; i<n; i++) {
    cin >> start >> end;
    upstair[start] = end;
  }
  for(int i=0; i<m; i++) {
    cin >> start >> end;
    downstair[start] = end;
  }
  int shortest = bfs(1, roll, upstair, downstair);
  cout << shortest << endl;
  return 0;
}
