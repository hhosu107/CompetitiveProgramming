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
    for(int i=0; i<upper_lim; i++) {
      if(len == 0) {
        a[len] = i;
        print_perm(orig, a, len + 1, maxlen, i, upper_lim);
      } else {
        for(int i=index; i<upper_lim; i++) {
          a[len] = i;
          print_perm(orig, a, len + 1, maxlen, i, upper_lim);
        }
      }
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
  vector<int> a(8, -1);
  print_perm(orig, a, 0, m, 0, n);
  return 0;
}
