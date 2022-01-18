#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int root(int a, vector<int> &parents) {
  if (a == parents[a]) return a;
  return parents[a] = root(parents[a], parents);
}

void connect(vector<int> &edge, vector<int> &parents) {
  edge[0] = root(edge[0], parents);
  edge[1] = root(edge[1], parents);
  if (edge[0] != edge[1])
    parents[edge[1]] = edge[0];
}

int countParents(vector<int> &parents) {
  unordered_set<int> s;
  for(auto parent: parents)
    s.insert(root(parent, parents));
  return s.size();
}

int ccs(int n, vector<vector<int>> &edges) {
  vector<int> parents(n);
  for(int i=0; i<n; i++)
    parents[i] = i;
  int ccs = 0;
  for(auto edge: edges)
    connect(edge, parents);
  ccs = countParents(parents);
  return ccs;
}

int main () {
  int n, m;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  vector<vector<int>> edges(m, vector<int>(2));
  for(auto& edge: edges) {
    cin >> edge[0] >> edge[1];
    edge[0]--;
    edge[1]--;
  }
  int cc = ccs(n, edges);
  cout << cc << '\n';
  return 0;
}
