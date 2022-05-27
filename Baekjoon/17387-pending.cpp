#include<iostream>
#include<algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

int main () {
  pii l1, l2, r1, r2;
  cin >> l1.first >> l1.second >> r1.first >> r1.second >> l2.first >> l2.second >> r2.first >> r2.second;
  if (l1.first > l2.first || (l1.first == l2.first && l1.second > l2.second)) {
    swap(l1, l2);
  }
  if (r1.first > r2.first || (r1.first == r2.first && r1.second > r2.second)) {
    swap(r1, r2);
  }
  // Slope:
  // (l2.y - l1.y) / (l2.x - l1.x)
  // (r2.y - r1.y) / (r2.x - r1.x).
  // y = (l2.y - l1.y) / (l2.x - l1.x) * (x - l1.x) + l1.y
  // y = (r2.y - r1.y) / (r2.x - r1.x) * (x - r1.x) + r1.y
  // if both (l2.x - l1.x) and (r2.x - r1.x) are non-zero,
  // then they crosses at:
  // (l1.y - r1.y) = (r2.y - y1.y) / (r2.x - r1.x) * (x - r1.x) - (l2.y - l1.y)
  // / (l2.x - l1.x) * (x - l1.x)
  // (l1.y - r1.y) * (r2.x - r1.x) * (l2.x - l1.x) = (r2.y - r1.y) * (l2.x -
  // l1.x) * (x - r1.x) - (l2.y - l1.y) * (r2.x - r1.x) * (x - l1.x)
  // Compute each coef.
  ll lhs = (l1.second - r1.second) * (r2.first - r1.first) * (l2.first - l1.first);
  ll rhs_x1 = (r2.second - r1.second) * (l2.first - l1.first);
  ll rhs_x2 = -(l2.second - l1.second) * (r2.first - r1.first);
  ll rhs_x3 = rhs_x1 * (-r1.first) + rhs_x2 * (-l1.first);
  // lhs = (rhs_x1 + rhs_x2) x + rhs_x3
  if (rhs_x1 + rhs_x2 == 0) {
    if (lhs != rhs_x3) {
      cout << "0\n";
      return 0;
    } else {
      cout << "1\n";
      return 0;
    }
  }
  else {
    ld x = (ld)(lhs - rhs_x3) / (ld)(rhs_x1 + rhs_x2);
    ld y = (ld)(l2.second - l1.second) / (ld)(l2.first - l1.first) * (ld)(x - l1.first) + (ld)l1.second;
    if (l1.first == l2.first) {
    } else if (r1.first == r2.first) {
    } else {
      if (x < l1.first || x > l2.first || x < l1.second || x > l2.second || x < r1.first || x > r2.first || y < r1.second || y > r2.second) {
        cout << "0\n";
        return 0;
      } else {
        cout << "1\n";
        return 0;
      }
    }
  }
  return 0;
}

