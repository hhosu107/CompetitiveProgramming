#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int query_string_len = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  vector<vector<bool>> pal(n, vector<bool>(n));
  for(int i=0; i<n; i++) {
    pal[i][i] = true;
  }
  for(int i = n - 2; i>=0; i--) {
    for(int j = i + 1; j<n; j++) {
      if (j == i + 1) pal[i][j] = (a[i] == a[j]);
      else pal[i][j] = (pal[i + 1][j - 1] && a[i] == a[j]);
    }
  }
  int m;
  cin >> m;
  for(int i=0; i<m; i++) {
    int s, e;
    cin >> s >> e;
    cout << (pal[s - 1][e - 1] ? 1 : 0) << '\n';
  }
  return 0;
}

