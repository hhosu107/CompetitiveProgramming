#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> elems;

void print_perm(int orig[], vector<int> a, vector<bool> used, int len, int maxlen, int upper_lim) {
  if (len == maxlen) {
    vector<int> elem(maxlen);
    for(int i=0; i<maxlen; i++) {
      elem[i] = orig[a[i]];
    }
    elems.push_back(elem);
    return;
  } else {
    for(int i=0; i<upper_lim; i++) {
      if (!used[i]) {
        used[i] = true;
        a[len] = i;
        print_perm(orig, a, used, len + 1, maxlen, upper_lim);
        used[i] = false;
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int orig[8];
  elems = vector<vector<int>>();
  for(int i=0; i<n; i++)
    cin >> orig[i];
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(orig[i] > orig[j])
        swap(orig[i], orig[j]);
    }
  }
  vector<int> a(8, -1);
  vector<bool> used(8, false);
  print_perm(orig, a, used, 0, m, n);
  sort(elems.begin(), elems.end());
  elems.erase(unique(elems.begin(), elems.end()), elems.end());
  for(int i=0; i<elems.size(); i++) {
    for(int j=0; j<m; j++)
      cout << elems[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
