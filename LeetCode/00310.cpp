#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
  vector<int> ans;
  if (n == 1) {
    ans.push_back(0);
    return ans;
  }
  vector<vector<int>> adj(n);
  for (auto e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }
  vector<int> degree(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j : adj[i]) {
      degree[i]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (degree[i] == 1) {
      q.push(i);
    }
  }
  int remaining_nodes = n;
  while (remaining_nodes > 2) {
    remaining_nodes -= q.size();
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int cur = q.front();
      q.pop();
      for (int j : adj[cur]) {
        degree[j]--;
        if (degree[j] == 1) {
          q.push(j);
        }
      }
    }
  }
  while (!q.empty()) {
    ans.push_back(q.front());
    q.pop();
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> edges(n - 1, vector<int>(2));
  for (auto &edge : edges)
    cin >> edge[0] >> edge[1];
  vector<int> ans = findMinHeightTrees(n, edges);
  for (auto a : ans)
    cout << a << " ";
  cout << endl;
  return 0;
}
