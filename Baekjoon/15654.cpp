#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_perm(int orig[], int a[], int len, int maxlen, int index, int n) {
  if (len == maxlen) {
    for(int i=0; i<maxlen; i++) {
      cout << a[i] << " ";
    } cout << '\n';
    return;
  } else if (index == n) {
    return;
  } else {
    /* Write down a loop that starts always from 0th index.
     * This problem has to contain all permutations. */
    a[len] = orig[index];
    print_perm(orig, a, len + 1, maxlen, index + 1, n);
    a[len] = 0;
    print_perm(orig, a, len, maxlen, index + 1, n);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int orig[8] = {0};
  for(int i=0; i<n; i++) {
    cin >> orig[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(orig[i] > orig[j])
        swap(orig[i], orig[j]);
    }
  }
  int a[8] = {0};
  print_perm(orig, a, 0, m, 0, n);
  return 0;
}
