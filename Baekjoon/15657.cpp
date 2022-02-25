#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_perm(int orig[], vector<int> a, int len, int maxlen, int index, int upper_lim) {
  if (len == maxlen) {
    for(int i=0; i<maxlen; i++) {
      cout << orig[a[i]] << " ";
    } cout << '\n';
    return;
  } else {
    for(int i=index; i<upper_lim; i++) {
      a[len] = i;
      print_perm(orig, a, len + 1, maxlen, i, upper_lim);
      a[len] = -1;
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
  for(int i=0; i<n; i++)
    cin >> orig[i];
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(orig[i] > orig[j])
        swap(orig[i], orig[j]);
    }
  }
  vector<int> a(8, -1);
  print_perm(orig, a, 0, m, 0, n);
  return 0;
}
