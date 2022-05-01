#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  vector<int> inward(N);
  for(int i=0; i<M; i++) {
    int a, b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    inward[b-1]++;
  }
  queue<int> q;
  for(int i=0; i<N; i++) {
    if(inward[i] == 0) {
      q.push(i);
    }
  }
  vector<int> partial_order(N);
  vector<bool> visited(N);
  int partial_index = 0;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    partial_order[partial_index++] = v;
    visited[v] = true;
    for(int u: G[v]) {
      inward[u]--;
      if(inward[u] == 0) {
        q.push(u);
      }
    }
  }
  for(int i=0; i<N; i++) {
    if(!visited[i]) {
      partial_order[partial_index++] = i;
    }
  }
  for(int i=0; i<N; i++) {
    cout << partial_order[i] + 1 << " ";
  }
  cout << '\n';
  return 0;
}
