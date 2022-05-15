#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

/* Original idea was:
 * jewel을 무게 단위 당 가치로 정렬해서, 높은 것 부터 순서대로 들어갈 수 있는
 * 가장 작은 가방을 찾으려고 함.
 * 그런데 그러면 가장 작은 가방을 찾는 과정에서 해시 충돌이 엄청 많이 발생해서
 * 결국 망함. 다른 방법을 써야 한다.
 */
int find_minimal_space(vector<ll> cap, vector<bool> occ, int l, int r, int w) {
  if (l > r) return -1;
  if (l == r) {
    if (occ[l]) return -1;
    return l;
  }
  int m = (l + r) / 2;
  if (cap[m] >= w) {
    if ((m == 0 || cap[m - 1] < w)) {
      if (!occ[m]) return m;
      else return find_minimal_space(cap, occ, m + 1, r, w);
    } else {
      int exception_index = 0;
      if (!occ[m]) exception_index = m;
      else exception_index = find_minimal_space(cap, occ, m + 1, r, w);
      int left_index = find_minimal_space(cap, occ, l, m - 1, w);
      if (left_index == -1) return exception_index;
      else return left_index;
    }
  } else return find_minimal_space(cap, occ, m + 1, r, w);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<pll> jewels(n);
  vector<ll> c(k);
  for(auto &j: jewels)
    cin >> j.second >> j.first;
  for(auto &ca: c)
    cin >> ca;
  auto cmp = [](const pll &a, const pll &b) -> bool {
    return ((a.first * b.second < b.first * a.second) || (a.first * b.second == b.first * a.second && a.second < b.second));
  };

  priority_queue<pll, vector<pll>, decltype(cmp)> pq(cmp);
  sort(jewels.begin(), jewels.end(), cmp);
  sort(c.begin(), c.end());
  return 0;
}

