#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
/* B. Array Eversion
 * a: array. x=a_n. a is partitioned by left/right: left contains <=x, right
 * contains >x/ Order preserving. Then the array is replaced with the
 * concatenation.
 * Compute the minimum number k such that the array stops changing.
 * Sol) How many operations are needed to make x=a_n maximum with this
 * operation? == Find longest decreasing sequence from the maximum value from
 * the right.
 * */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n;
    cin >> T;
    for(int t=0; t<T; t++){
      cin >> n;
      vector<int> values = vector<int>(n);
      for (auto& val: values)
        cin >> val;
      int max = -1;
      int idx = -1;
      for(int i=0; i<n; i++){
        if (max <= values[i]) {
          max = values[i];
          idx = i;
        }
      }
      if (idx == n - 1) cout << "0\n";
      else {
        int curr = 0;
        int len = 0;
        for(int i=n-1; i>=idx; i--) {
          if (values[i] > curr) {
            curr = values[i];
            len++;
          }
        }
        cout << len - 1 << '\n';
      }
    }
    return 0;
}
