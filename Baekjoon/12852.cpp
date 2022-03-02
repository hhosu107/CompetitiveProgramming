#include<iostream>
#include<vector>

using namespace std;

using p = pair<int, int>;

int main () {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n + 1, {0, 0});
  for(int i=2; i<=n; i++) {
    p pa = {v[i-1].first + 1, i - 1};
    if (i % 2 == 0) {
      if (v[i/2].first + 1 < pa.first) {
        pa = {v[i/2].first + 1, i/2};
      }
    }
    if (i % 3 == 0) {
      if (v[i/3].first + 1 < pa.first) {
        pa = {v[i/3].first + 1, i/3};
      }
    }
    v[i] = pa;
  }
  cout << v[n].first << endl;
  int last = n;
  while(last > 1) {
    cout << last << " ";
    last = v[last].second;
  }
  cout << 1 << endl;
  return 0;
}
