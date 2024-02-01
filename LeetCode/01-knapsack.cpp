#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Query {
  int p;
  int price;
  Query() : p(0), price(0) {}
  Query(int p, int price) : p(p), price(price) {}
};

int main() {
  int n;
  cin >> n;
  vector<Query> queries;
  int full_budget = 0;
  for (int i = 0; i < n; i++) {
    int p, price;
    cin >> p >> price;
    full_budget = max(full_budget, p);
    if (p >= price)
      queries.push_back(Query(p, price));
  }
  sort(queries.begin(), queries.end(), [](Query a, Query b) {
    return (a.price < b.price || (a.price == b.price && a.p > b.p));
  });
  int ans = 0;
  int rem_budget = full_budget;
  for (int i = 0; i < n; i++) {
    if (queries[i].p <= rem_budget) {
      ans += 1;
      rem_budget -= queries[i].price;
    }
  }
  cout << ans << endl;
  return 0;
}
