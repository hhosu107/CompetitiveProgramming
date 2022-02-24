#include<iostream>
#include<array>
#include<vector>

using namespace std;

array<array<int, 1025>, 1025> rowsum = {}, areasum = {};
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int num;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) {
      cin >> num;
      rowsum[i+1][j+1] = rowsum[i+1][j] + num;
      areasum[i+1][j+1] = areasum[i][j+1] + rowsum[i+1][j+1];
    }
  vector<int> res = vector<int>(m);
  int x1, y1, x2, y2;
  for(int i=0; i<m; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    res[i] = areasum[x2][y2] - areasum[x2][y1-1] - areasum[x1-1][y2] + areasum[x1-1][y1-1];
  }
  for(auto r : res)
    cout << r << '\n';
  return 0;
}
