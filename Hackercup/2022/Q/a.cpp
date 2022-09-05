#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main () {
  /*
   * n parts, style S_i.
   * 2 display: each holds K parts.
   * Put each n parts into one of the two cases so that neither case ends up
   * with two different parts of the same style,
   * neither case has more than K parts total.
   * Determine whether this is possible.
   */
  /* Sol)
   * If any style occurs more than 3rd, impossible.
   * If 2 * K < n, impossible.
   * Count number of doubly occurring styles. if # different styles - # doubly
   * occuring styles > 2 * (K - # doubly occuring styles), impossible.
   * o.w., possible.
   */
  int T;
  cin >> T;
  for(int t=1; t<=T; t++) {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> occurrences;
    int unique_styles = 0;
    int double_styles = 0;
    bool triple_flag = false;
    for(int i=0; i<n; i++) {
      int style;
      cin >> style;
      occurrences[style]++;
      if (occurrences[style] == 1) {
        unique_styles += 1;
      } else if (occurrences[style] == 2) {
        double_styles += 1;
      } else {
        triple_flag = true;
      }
    }
    cout << "Case #" << t << ": ";
    if (triple_flag) {
      cout << "NO\n";
    } else if (2 * k < n) {
      cout << "NO\n";
    } else if (unique_styles - double_styles > 2 * (k - double_styles)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}

