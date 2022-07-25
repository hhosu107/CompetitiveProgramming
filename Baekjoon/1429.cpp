#include<bits/stdc++.h>
using namespace std;

int min_mate_cnt;

void select_k_numbers_from_pool(int n, int k, int used, int curr, int indicator, unordered_map<int, unordered_set<int>> &love_map) {
  if (min_mate_cnt < n + 1)
    return;
  if (indicator == (1 << n) - 1) {
    min_mate_cnt = used;
    return;
  }
  if (curr == n || used == k) {
    return;
  }
  select_k_numbers_from_pool(n, k, used, curr + 1, indicator, love_map);
  int next_indicator = indicator;
  next_indicator |= (1 << curr);
  for (int p : love_map[curr]) {
    next_indicator |= (1 << p);
  }
  select_k_numbers_from_pool(n, k, used + 1, curr + 1, next_indicator, love_map);
}

int main () {
  int n, m;
  cin >> n >> m;
  vector<string> love_matrix(n);
  for(string &l: love_matrix)
    cin >> l;
  unordered_map<int, unordered_set<int>> love_map;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if (love_matrix[i][j] == '1') {
        love_map[i].insert(j + n);
        love_map[j + n].insert(i);
      }
    }
  }
  if (love_map.size() < n + m) {
    cout << -1 << endl;
    return 0;
  }
  min_mate_cnt = n + m + 1;
  for(int i=2; i<=n + m; i++) {
    select_k_numbers_from_pool(n + m, i, 0, 0, 0, love_map);
    if (min_mate_cnt < n + m + 1) break;
  }
  cout << min_mate_cnt << endl;
  return 0;
}
