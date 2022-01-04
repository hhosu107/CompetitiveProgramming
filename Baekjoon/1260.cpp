#include<iostream>
#include<set>
#include<queue>
#include<stack>

using namespace std;

void dfs(vector<set<int>> &points, vector<bool> &marked, int pt) {
  if(marked[pt]) return;
  else {
    cout << pt << " ";
    marked[pt] = true;
    for (auto p : points[pt]) {
      dfs(points, marked, p);
    }
  }
}

void bfs(vector<set<int>> &points, vector<bool> &marked, int pt) {
  queue<int> nextpts;
  nextpts.push(pt);
  cout << pt << " ";
  marked[pt] = true;
  while(!nextpts.empty()) {
    int next = nextpts.front();
    nextpts.pop();
    for(auto p : points[next]) {
      if(!marked[p]) {
        cout << p << " ";
        marked[p] = true;
        nextpts.push(p);
      }
    }
  }
  cout << '\n';
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, v;
  cin >> n >> m >> v;
  int start, end;
  vector<set<int>> points = vector<set<int>>(n + 1);
  for(int i=0; i<m; i++){
    cin >> start >> end;
    points[start].insert(end);
    points[end].insert(start);
  }
  vector<bool> marked = vector<bool>(n + 1);
  dfs(points, marked, v);
  cout << '\n';
  marked = vector<bool>(n + 1);
  bfs(points, marked, v);
  return 0;
}
