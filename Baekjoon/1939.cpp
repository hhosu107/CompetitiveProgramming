#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

using pii = pair<int, int>;
using pipi = pair<int, pair<int, int>>;

int find (vector<int>& parent, int c) {
  if (parent[c] == c) return c;
  return parent[c] = find(parent, parent[c]);
}

bool merge(vector<int>& parent, vector<int>& ranks, int c1, int c2) {
  int p1 = find(parent, c1);
  int p2 = find(parent, c2);
  if (p1 == p2) return false;
  if (ranks[p1] > ranks[p2]) {
    parent[p2] = p1;
  } else {
    parent[p1] = p2;
    if (ranks[p1] == ranks[p2]) ranks[p2]++;
  }
  return true;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pipi> weights(m);
  int max_weight = -1;
  for(pipi& w: weights){
    cin >> w.second.first >> w.second.second >> w.first;
    max_weight = max(max_weight, w.first);
  }
  vector<int> parent(n + 1), ranks(n + 1, 0);
  for(int i=1; i<=n; i++)
    parent[i] = i;
  int s, e;
  cin >> s >> e;
  priority_queue<pipi> pq;
  for(pipi w: weights) {
    pq.push(w);
  }
  while(!pq.empty()) {
    pipi curr = pq.top();
    pq.pop();
    bool merged = merge(parent, ranks, curr.second.first, curr.second.second);
    if (merged) {
      max_weight = min(max_weight, curr.first);
      if (find(parent, s) == find(parent, e)) {
        cout << max_weight << '\n';
        return 0;
      }
    }
  }
  return 0;
}
