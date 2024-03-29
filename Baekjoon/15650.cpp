#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_perm(int a[], int len, int maxlen, int upper_lim) {
  if (len == maxlen) {
    for(int i=0; i<maxlen; i++) {
      cout << a[i] << " ";
    } cout << '\n';
  } else if ((len > 0) && a[len - 1] == upper_lim) {
    return;
  } else {
    for(int i=(len == 0 ? 1 : a[len - 1] + 1); i <= upper_lim; i++) {
      a[len] = i;
      print_perm(a, len + 1, maxlen, upper_lim);
    }
  }
}

int main () {
  int n, m;
  cin >> n >> m;
  int a[8] = {0};
  print_perm(a, 0, m, n);
  return 0;
}
