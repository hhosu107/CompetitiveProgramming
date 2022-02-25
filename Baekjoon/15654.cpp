#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_perm(int orig[], vector<int> a, int len, int maxlen, int n) {
  if (len == maxlen) {
    for(int i=0; i<maxlen; i++) {
      cout << orig[a[i]] << " ";
    } cout << '\n';
    return;
  } else {
    for(int i=0; i<n; i++) {
      if (len == 0) {
        a[len] = i;
        print_perm(orig, a, len + 1, maxlen, n);
      } else {
    /* Write down a loop that starts always from 0th index.
     * This problem has to contain all permutations. */
        if (find(a.begin(), a.end(), i) == a.end()) {
          a[len] = i;
          print_perm(orig, a, len + 1, maxlen, n);
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
  vector<int> a(8, -1);
  print_perm(orig, a, 0, m, n);
  return 0;
}
