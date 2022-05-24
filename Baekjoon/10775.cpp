#include<bits/stdc++.h>
using namespace std;

int find_parent(vector<int> &parent, int v) {
  if(parent[v] == v) return v;
  parent[v] = find_parent(parent, parent[v]);
  return parent[v];
}

int main () {
  int g, p;
  cin >> g >> p;
  vector<int> gi(p);
  for(auto &x: gi) cin >> x;
  vector<int> parent(g + 1);
  for(int i=0; i<=g; i++)
    parent[i] = i; // Initially, all airports are empty.
  int cnt = 0;
  for(int i=0; i<p; i++) {
    int k = find_parent(parent, gi[i]); // parent[k] == k means that k is the place that ith plane can be assigned (it was found greedily; since initially parent[i] == i.)
    if (k == 0) // 1 ~ gi[i] is fully assigned.
      break;
    parent[k] = k-1; // Since k is consumed, assign k-1 to parent[k] to mark k is consumed. So this means we have to try k-1th airport when a plane requested kth airport to dock. Here, note that if nonzero k is found, it means that parent[k] was equal to k, and thus we can use kth airport to dock.
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
