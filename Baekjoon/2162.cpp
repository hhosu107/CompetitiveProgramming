#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<unordered_set>
using namespace std;

// Counter ClockWise check
// And then segments intersection check
// https://jason9319.tistory.com/358

using ll = int64_t;
using pll = pair<ll, ll>;
ll ccw(pll a, pll b, pll c) {
  // Area of triangle = (v2 - v1)(v3 - v1) = (x2 - x1)(y3 - y1) - (x3 - x1)(y2 - y1)
  // == x1y2 - x2y1 + x2y3 - x3y2 + x3y1 - x1y3.
  // 1) parallel: it equals to 0.
  // 2) counter clockwise: positive.
  // 3) clockwise: negative.
  ll op = a.first * b.second + b.first * c.second + c.first * a.second;
  op -= (a.second*b.first + b.second * c.first + c.second * a.first);
  if (op > 0LL) return 1;
  else if (op == 0LL) return 0;
  else return -1;
}

using ppll = pair<pll, pll>;
ll isIntersect(ppll x, ppll y) {
  // If A-B and C-D crosses, their CCW (C-D-A, C-D-B) must have different sign.
  // However, if the extension of C-D cross A-B whereas C-D doesn't cross A-B,
  // we miss this case. Thus, do the CCW for vice versa (A-B-C, A-B-D).
  // There is one last case.
  // IF CCW(A-B-C) * CCW(A-B-D) == CCW(C-D-A) * CCW(C-D-B) == 0, then every 4
  // points are on the same line. In this case, first, WLoG, make a <= b and c <=
  // d (using operator of pair<ll, ll>). And then check c<=b && a <= d. This
  // means: B is in the middle of C-D && C is in the middle of A-B // or A is in
  // the middle of C-D and D is in the middle of A-B, which means they crosses.
  // Otherwise, only check CCW(A-B-C) * CCW(A-B-D) <= 0 and CCW(C-D-A) *
  // CCW(C-D-B) <= 0.
  pll a = x.first;
  pll b = x.second;
  pll c = y.first;
  pll d = y.second;
  ll ab = ccw(a, b, c) * ccw(a, b, d);
  ll cd = ccw(c, d, a) * ccw(c, d, b);
  if (ab == 0 && cd == 0) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return (c <= b && a <= d);
  }
  return ab <= 0 && cd <= 0;
}

int find(vector<int> &parent, int x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent, parent[x]);
}

bool has_same_parent(vector<int>&parent, int x, int y) {
  return find(parent, x) == find(parent, y);
}

bool unify(vector<int> &parent, vector<int> &ranks, int x, int y) {
  int px = find(parent, x);
  int py = find(parent, y);
  if (px == py) return false;
  if (ranks[px] < ranks[py])
    swap(px, py);
  parent[py] = px;
  ranks[px] += ranks[py]; // group size-based merge leads trackable maximum group size.
  return true;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ppll> segs(n);
  for(ppll& seg: segs)
    cin >> seg.first.first >> seg.first.second >> seg.second.first >> seg.second.second;
  vector<int> parent(n);
  vector<int> ranks(n, 1);
  for(int i=0; i<n; i++)
    parent[i] = i;
  for(int i=0; i<n-1; i++) {
    for(int j=i + 1; j<n; j++) {
      if (has_same_parent(parent, i, j)) // reduce the number of unions.
        continue;
      if (isIntersect(segs[i], segs[j])) { // returns true at most n-1 times because of the previous clause.
        unify(parent, ranks, i, j);
      }
    }
  }
  unordered_set<int> groups;
  int max_group_size = 0;
  for(int i=0; i<n; i++) {
    int pi = find(parent, i);
    groups.insert(pi);
    max_group_size = max(max_group_size, ranks[pi]);
  }
  cout << groups.size() << '\n' << max_group_size << '\n';
  return 0;
}
