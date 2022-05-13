#include<bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;

vector<vector<int>> make_comb;

void make_combination(int index, int used, int pool, vector<int> &arr, vector<int> &comb) {
  if (used == comb.size()) {
    make_comb.push_back(comb);
  } else if (index == pool) {
    return;
  } else {
    comb[used] = arr[index];
    make_combination(index + 1, used + 1, pool, arr, comb);
    make_combination(index + 1, used, pool, arr, comb);
  }
}

void make_combination_init(int pool) {
  int comb_size = pool / 2;
  vector<int> arr(pool);
  vector<int> comb(comb_size);
  for(int i=0; i<pool; i++)
    arr[i] = i;
  int index = 0, used = 0;
  make_combination(index, used, pool, arr, comb);
}

double vector_sum(vector<pll> &points, vector<int> &comb) {
  vector<bool> check(points.size());
  for(auto c: comb)
    check[c] = true;
  pll sum = make_pair(0, 0);
  for(int i=0; i<points.size(); i++) {
    int sign = (check[i] ? -1 : 1);
    sum.first += sign * points[i].first;
    sum.second += sign * points[i].second;
  }
  long long dist_sq = sum.first * sum.first + sum.second * sum.second;
  double dist = sqrt((double)dist_sq);
  return dist;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<pll> points(n);
    for(auto &p: points) {
      cin >> p.first >> p.second;
    }
    make_comb = vector<vector<int>>();
    make_combination_init(n);

    double min_dist = numeric_limits<double>::max();
    for(vector<int> c: make_comb) {
      double dist = vector_sum(points, c);
      min_dist = min(min_dist, dist);
    }
    cout << fixed << setprecision(12) << min_dist << '\n';
  }
  return 0;
}
