#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>
using namespace std;

// Counter ClockWise check
// And then segments intersection check
// https://jason9319.tistory.com/358

using pii = pair<int, int>;
int ccw(pii a, pii b, pii c) {
  // Area of triangle = (v2 - v1)(v3 - v1) = (x2 - x1)(y3 - y1) - (x3 - x1)(y2 - y1)
  // == x1y2 - x2y1 + x2y3 - x3y2 + x3y1 - x1y3.
  // 1) parallel: it equals to 0.
  // 2) counter clockwise: positive.
  // 3) clockwise: negative.
  int op = a.first * b.second + b.first * c.second + c.first * a.second;
  op -= (a.second*b.first + b.second * c.first + c.second * a.first);
  if (op > 0) return 1;
  else if (op == 0) return 0;
  else return -1;
}

using ppii = pair<pii, pii>;
int isIntersect(ppii x, ppii y) {
  // In general:
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
  // For this problem, since all 4 points are on the convex polygon, all ab and
  // cd must be negative.
  pii a = x.first;
  pii b = x.second;
  pii c = y.first;
  pii d = y.second;
  int ab = ccw(a, b, c) * ccw(a, b, d);
  // ll cd = ccw(c, d, a) * ccw(c, d, b);
  return (ab < 0 ? 1 : 0);
}

int main () {
  ppii x, y;
  cin >> x.first.first >> x.first.second >> x.second.first >> x.second.second;
  cin >> y.first.first >> y.first.second >> y.second.first >> y.second.second;
  cout << isIntersect(x, y) << endl;
  return 0;
}
