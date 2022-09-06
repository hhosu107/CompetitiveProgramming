#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int count_leaf(vector<vector<int>>& childs, int k) {
  if (childs[k].empty()) return 1;
  int sum = 0;
  for (auto& c : childs[k]) {
    sum += count_leaf(childs, c);
  }
  return sum;
}

int main () {
  int n;
  cin >> n;
  vector<int> parent(n);
  vector<vector<int>> childs(n);
  for (int i=0; i<n; i++){
    cin >> parent[i];
    if (parent[i] != -1) childs[parent[i]].push_back(i);
  }
  int whole_leaves = 0;
  for(int i=0; i<n; i++) {
    if (childs[i].empty()) whole_leaves++;
  }
  int k;
  cin >> k;
  int deleted_leaves = count_leaf(childs, k);
  if (parent[k] == -1) {
    cout << 0 << endl;
  } else if (childs[parent[k]].size() == 1) {
    cout << whole_leaves - deleted_leaves + 1 << endl;
  } else {
    cout << whole_leaves - deleted_leaves << endl;
  }
  return 0;
}
