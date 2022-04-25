// Can we track subtree maximum?
// Additionally, if there are any subtree with the lower amount of the
// root of subtree, can we lend that value to the subtree to maximize
// path maximum?
// ex) 50 -> 20 -> 60
//                /
//               40
// If we give 60 to 40, we get score max(60, 40) + max(50, 20) = 110.
// With this process, if we make all local-maxima on the leaf,
// we can just sum up them.
// Method:
// 1. Maintain subtree maxima.
// 2. From the root node, do tree dfs with the following steps:
//   a. If the node is a leaf, stop.
//   b. If every subtree maxima is larger than or equal to the node value,
//       just make the node value as 0.
//   c. If not, move the node value to the subtree with smallest value.
//   d. DFS with each subtree.
// 3. After 2., only leaves have non-zero value. Sum up them.
//
// Update: There is a counter example.
/*
 * 50                                 : 그냥 50 + 51 + 45 + 5 (40, 41, 3, 5 순 activate)가 더 크지 않나? 40 + 51 + 50 + 5 (3, 5, 40, 51 activate)보다는?
|  \
40  40
      |  \
     51  45
           |  \
           5   3
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll dfs_local_maxima(unordered_map<int, vector<int>> &children,
                      int node, const vector<ll> &val,
                      vector<ll> &subtree_maxima) {
  if (children.find(node) == children.end()) {
    subtree_maxima[node] = val[node];
    return val[node];
  }
  ll max_subtree_maxima = 0;
  for(int child: children[node]) {
    int sub_maxima = dfs_local_maxima(children, child, val, subtree_maxima);
    if (sub_maxima > max_subtree_maxima) {
      max_subtree_maxima = sub_maxima;
    }
  }
  subtree_maxima[node] = max(val[node], max_subtree_maxima);
  return subtree_maxima[node];
}

void dfs_lend_node_to_smallest_subtree(unordered_map<int, vector<int>> &children,
                                     int node, vector<ll> &val,
                                     const vector<ll> &subtree_maxima) {
  if (children.find(node) == children.end()) {
    return;
  }
  int min_index = -1;
  ll min_subtree_maxima = val[node];
  for(int child: children[node]) {
    if (subtree_maxima[child] < min_subtree_maxima) {
      min_index = child;
      min_subtree_maxima = subtree_maxima[child];
    }
  }
  if (min_index != -1) {
    val[min_index] = val[node];
  }
  val[node] = 0;
  for(int child: children[node]) {
    dfs_lend_node_to_smallest_subtree(children, child, val, subtree_maxima);
  }
}

using ll = long long;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for(int t=1; t<=T; t++){
    int n;
    cin >> n;
    vector<ll> val(n+1);
    for(int i=1; i<=n; i++) cin >> val[i];
    vector<int> parent(n+1);
    unordered_map<int, vector<int>> children;
    vector<bool> is_leaf(n+1, true);
    for(int i=1; i<=n; i++) {
      cin >> parent[i];
      is_leaf[parent[i]] = false;
      if (children.find(parent[i]) == children.end()) {
        children[parent[i]] = vector<int>();
      }
      children[parent[i]].push_back(i);
    }
    vector<ll> subtree_maxima(n+1, 0);
    ll dfs_local_maxima_root = dfs_local_maxima(children, 0, val, subtree_maxima);
    dfs_lend_node_to_smallest_subtree(children, 0, val, subtree_maxima);
    ll ans = 0;
    for(auto v: val)
      ans += v;
    cout << "Case #" << t << ": " << ans << '\n';
  }
  return 0;
}
