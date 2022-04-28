#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using plll = pair<ll, pll>;
using pdll = pair<double, pll>;

class graph {
  private:
    vector<pdll> g; // graph
    vector<pdll> t; // MST
    vector<ll> parent; // parent of each node
    int n; // number of nodes
    int m; // number of edges
    int edge_idx; // index of edge to be added
  public:
    graph(int n) {
      this->n = n;
      this->m = n * (n - 1) / 2;
      this->edge_idx = 0;
      g = vector<pdll>(m);
      t = vector<pdll>(n-1);
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
    void read_points() {
      double x, y;
      vector<pdd> pts = vector<pdd>(n);

      for(int i=0; i<n; i++) {
        cin >> x >> y;
        pts[i] = pdd(x, y);
      }
      int edge = 0;
      for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
          double d = sqrt(pow(pts[i].first - pts[j].first, 2) + pow(pts[i].second - pts[j].second, 2));
          g[edge] = pdll(d, pll(i, j));
          edge++;
        }
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
      double sum = 0;
      for(auto x: t) {
        sum += x.first;
      }
      cout << fixed << setprecision(2) << sum << '\n';
    }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int v;
  cin >> v;

  graph g(v);
  g.read_points();
  g.kruskal();
  g.print_weight_sum();
  return 0;
}
