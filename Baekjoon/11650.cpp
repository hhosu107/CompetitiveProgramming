#include<iostream>
#include<vector>

using namespace std;

struct point {
  int x;
  int y;
  point() : x(0), y(0) {}
  point(int x, int y) : x(x), y(y) {}
  bool operator<(point r) const {
    return x < r.x || (x == r.x && y < r.y);
  }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<point> pts = vector<point>(n, point());
  point x;
  for(int i=0; i<n; i++){
    cin >> x.x >> x.y;
    pts[i] = x;
  }
  sort(pts.begin(), pts.end());
  for(int i=0; i<n; i++)
    cout << pts[i].x << " " << pts[i].y << '\n';
  return 0;
}
