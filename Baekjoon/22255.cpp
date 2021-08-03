#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

typedef pair<int, int> pi;
const int _INT_MAX = 2147483647;

struct pt_len {
  int sx, sy, k;
  int weight;

  pt_len(int sx, int sy, int k, int weight) : sx(sx), sy(sy), k(k), weight(weight) {}
  bool operator<(const pt_len &right) const {
    if (weight > right.weight) return true;
    else if (sx > right.sx) return true;
    else if (sy > right.sy) return true;
    else if (k > right.k) return true;
    return false;
  }
};

int dijkstra(int N, int M, vector<vector<int>> graph, int sx, int sy, int dx, int dy){
  vector<vector<vector<int>>> weight = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(3, _INT_MAX)));
  priority_queue<pt_len> pq = priority_queue<pt_len>();
  weight[sx][sy][0] = 0;
  pq.push(pt_len(sx, sy, 0, 0));
  while(!pq.empty()) {
    pt_len top = pq.top();
    pq.pop();
    if (top.weight > weight[top.sx][top.sy][top.k]) continue;
    for(int i=0; i<4; i++){
      int ny = top.sy + (i == 0 ? 1 : (i == 2 ? -1 : 0));
      int nx = top.sx + (i == 1 ? 1 : (i == 3 ? -1 : 0));
      if (0 > nx || N <= nx || 0 > ny || M <= ny) continue;
      if ((i == 0 || i == 2) && top.k == 0) continue;
      if ((i == 1 || i == 3) && top.k == 1) continue;
      if (graph[nx][ny] == -1) continue;
      int alt = top.weight + graph[nx][ny];
      if (alt < weight[nx][ny][(top.k + 1) % 3]){
        weight[nx][ny][(top.k + 1) % 3] = alt;
        pq.push(pt_len(nx, ny, (top.k + 1) % 3, alt));
      }
    }
  }
  int min_w = (weight[dx][dy][0] < weight[dx][dy][1] ? weight[dx][dy][0] : weight[dx][dy][1]);
  min_w = (min_w < weight[dx][dy][2] ? min_w : weight[dx][dy][2]);
  if (min_w == _INT_MAX) return -1;
  return min_w;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int sx, sy, dx, dy;
  cin >> sx >> sy >> dx >> dy;
  sx--;
  sy--;
  dx--;
  dy--;
  vector<vector<int>> graph = vector<vector<int>>(n, vector<int>(m));
  for (auto &row : graph){
    for(auto &cell : row){
      cin >> cell;
    }
  }
  int result = dijkstra(n, m, graph, sx, sy, dx, dy);
  cout << result << '\n';
  return 0;
}
