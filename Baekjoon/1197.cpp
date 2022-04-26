#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using plll = pair<ll, pll>;

class graph {
  private:
    vector<plll> g; // graph
    vector<plll> t; // MST
    vector<ll> parent; // parent of each node
    int n; // number of nodes
    int m; // number of edges
    int edge_idx; // index of edge to be added
  public:
    graph(int n, int m) {
      this->n = n;
      this->m = m;
      this->edge_idx = 0;
      g = vector<plll>(m);
      t = vector<plll>(n-1);
      parent.resize(n);
      for(int i=0; i<n; i++)
        parent[i] = i;
    }
    ll find_set(ll x) {
      // Parent of x is x itself
      if (x == parent[x])
        return x;
      // x doesn't represent its set.
      // Recursivelty call find_set on its parent
      parent[x] = find_set(parent[x]);
      return parent[x];
    }
    void read_edges() {
      ll u, v, w;
      for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        g[i] = plll(w, pll(u-1, v-1));
      }
    }
    void union_set(int u, int v) {
      parent[u] = parent[v];
    }
    void kruskal() {
      int u_represent, v_represent;
      sort(g.begin(), g.end()); // weight sort
      for(int i=0; i<m; i++) {
        u_represent = find_set(g[i].second.first);
        v_represent = find_set(g[i].second.second);
        if (u_represent != v_represent) { // they are not in the same tree
          t[edge_idx++] = g[i];
          union_set(u_represent, v_represent);
        }
      }
    }
    void print_weight_sum() {
      ll sum = 0;
      for(auto x: t) {
        sum += x.first;
      }
      cout << sum << '\n';
    }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int v, e;
  cin >> v >> e;

  graph g(v, e);
  g.read_edges();
  g.kruskal();
  g.print_weight_sum();
  return 0;
}
