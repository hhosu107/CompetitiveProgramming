#include<bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
  int idx;
  Point(int x, int y, int idx) : x(x), y(y), idx(idx) {}
  Point() : x(0), y(0) {}
  bool operator<(const Point& p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
  double tilt(const Point& p) {
    return abs((double)(y - p.y) / (double)(x - p.x));
  }
};

int main () {
  int n;
  cin >> n;
  vector<Point> points(n);
  int cnt = 0;
  for(Point& p : points) {
    cin >> p.x >> p.y;
    p.idx = cnt++;
  }
  sort(points.begin(), points.end());
  double tilting = points[0].tilt(points[1]);
  int ans_left = points[0].idx, ans_right = points[1].idx;
  if (ans_left > ans_right) swap(ans_left, ans_right);
  for(int i=1; i<n-1; i++) {
    double temp_tilting = points[i].tilt(points[i+1]);
    int left = points[i].idx, right = points[i+1].idx;
    if (left > right) swap(left, right);
    if (temp_tilting > tilting + 0.00000001) {
      tilting = temp_tilting;
      ans_left = left;
      ans_right = right;
    } else if (temp_tilting + 0.00000001 > tilting) {
      priority_queue<int, vector<int>, greater<int>> pq;
      pq.push(left);
      pq.push(right);
      pq.push(ans_left);
      pq.push(ans_right);
      int real_left = -1, real_right = -1;
      real_left = pq.top();
      pq.pop();
      if (pq.top() == real_left) pq.pop();
      real_right = pq.top();
      ans_left = real_left;
      ans_right = real_right;
    }
  }
  if (ans_left > ans_right) swap(ans_left, ans_right);
  cout << ans_left + 1 << " " << ans_right + 1 << endl;
  return 0;
}
// https://thunderinthesky.tistory.com/entry/elice-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%E2%85%A0-4-%ED%83%90%EC%9A%95%EC%A0%81-%EA%B8%B0%EB%B2%95
