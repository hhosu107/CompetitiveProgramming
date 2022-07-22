#include<bits/stdc++.h>
using namespace std;

struct Query {
  int query_type;
  int l_or_c;
  int r;
  Query(int query_type, int l_or_c, int r) : query_type(query_type), l_or_c(l_or_c), r(r) {}
  Query() : query_type(0), l_or_c(0), r(0) {}
  Query(int query_type, int l_or_c) : query_type(query_type), l_or_c(l_or_c), r(0) {}
};

// merge, find
int find(int u, vector<int> &fake_parent) {
  if (fake_parent[u] == u) return u;
  return fake_parent[u] = find(fake_parent[u], fake_parent);
}

void merge(int u, int v, vector<int> &fake_parent, vector<int> &tree_rank) {
  int pu = find(u, fake_parent);
  int pv = find(v, fake_parent);
  if (pu == pv) return;
  if (tree_rank[pu] > tree_rank[pv]) {
    swap(pu, pv);
  }
  fake_parent[pu] = pv;
  if (tree_rank[pu] == tree_rank[pv]) {
    tree_rank[pv]++;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> real_parent(n, -1);
  for(int i=1; i<n; i++) {
    int p;
    cin >> p;
    real_parent[i] = p - 1;
  }
  vector<Query> queries(q + n - 1);
  for(int i=0; i<n - 1 + q; i++) {
    int query_type;
    cin >> query_type;
    if (query_type == 0) {
      int c;
      cin >> c;
      queries[i] = Query(query_type, c - 1);
    } else {
      int l, r;
      cin >> l >> r;
      queries[i] = Query(query_type, l - 1, r - 1);
    }
  }
  vector<string> ans(q);
  reverse(queries.begin(), queries.end());
  vector<int> fake_parent(n, 0);
  for(int i=0; i<n; i++) {
    fake_parent[i] = i;
  }
  vector<int> tree_rank(n, 1);
  int connect_queries = 0;
  for(int i=0; i<q + n - 1; i++) {
    if (queries[i].query_type == 0) {
      int c = queries[i].l_or_c;
      merge(real_parent[c], c, fake_parent, tree_rank);
    } else {
      int pl = find(queries[i].l_or_c, fake_parent);
      int pr = find(queries[i].r, fake_parent);
      if (pl == pr) ans[connect_queries++] = "YES";
      else ans[connect_queries++] = "NO";
    }
  }
  reverse(ans.begin(), ans.end());
  for(string a: ans)
    cout << a << '\n';
  return 0;
}
