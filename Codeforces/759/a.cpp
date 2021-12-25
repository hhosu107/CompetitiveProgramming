#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
/* A. flower: 2 days of non-water = die, ith day watered: 1cm longer, i/i-1th day watered: 5cm longer, non-water of ith day: 0cm longer.
 * Height of the n day after? (starting from 1 day). If it dies, -1.*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n;
    cin >> T;
    for(int t=0; t<T; t++){
      cin >> n;
      vector<int> wat = vector<int>(n);
      int len = 1;
      for (int i=0; i<n; i++){
        cin >> wat[i];
        if (len == -1) continue;
        if (wat[i] == 0) {
          if (i > 0 && wat[i-1] == 0) {
            len = -1;
          }
        } else {
          if (i > 0 && wat[i-1] == 1) {
            len += 5;
          } else len += 1;
        }
      }
      cout << len << '\n';
    }
    return 0;
}
