/* https://justicehui.github.io/medium-algorithm/2019/01/01/UnionFind3/ */
#include<iostream>
#include<algorithm>
using namespace std;
int par[10000];
int ranks[10000];
void init(int n) {
  for(int i=1; i<=n; i++) {
    par[i] = i;
    ranks[i] = 1;
  }
}

int find(int v) {
  if (v == par[v]) return v;
  return par[v] = find(par[v]); // path compression
}

bool merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return true;
  // Attach u under v. Before do that, swap them if ranks[u] > ranks[v]
  if (ranks[u] > ranks[v]) swap(u, v);
  par[u] = v;
  if (ranks[u] == ranks[v]) ranks[v]++; // rank increases only if the tree with the same height becomes the child.
  return true;
}
