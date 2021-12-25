#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
/* C. Minimize Distance
 * n depots at point x_i. n bags for each of teapots.
 * you and n bags are originally located at 0. Can only carry up to k bags at a
 * time. Must collect required number of goods from the origin, deliver them to
 * depots, and return to the origin.
 * Calculate min distance to cover to deliver all the bags of goods.
 * Do not have to return to the origin after all delivery ends.
 * Note: negative distance is included.
 * Sol) From each side, find kth closest points. Select greedily closest points.
 * If there are less than or equal to k depots to visit and both side are
 * required, visit closer side; return; and then visit the farther side and
 * stop.
 * */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n, k;
    cin >> T;
    for(int t=0; t<T; t++){
      cin >> n >> k;
      vector<int> values = vector<int>(n);
      for (auto& val: values)
        cin >> val;
      sort(values.begin(), values.end());
      int neg = 0, pos = 0;
      bool foundneg = false, foundpos = false;
      for(int i=0; i<n; i++){
        if (!foundneg && values[i] >= 0) {
          neg = i - 1;
          foundneg = true;
        }
        if (!foundpos && values[i] > 0) {
          pos = i;
          foundpos = true;
        }
      }
      int remneg = 0, rempos = 0;
      long long int steps = 0L;
      for(int i=0; i<=neg; i++){
        if (i == 0) {
          remneg = -values[i];
        }
        else if (i % k == 0){
          steps += 2 * (-values[i]);
        }
      }
      for(int i=n-1; i>=pos; i--){
        if (i == n - 1) {
          rempos = values[i];
        }
        else if ((n - i - 1) % k == 0) {
          steps += 2 * values[i];
        }
      }
      if (remneg < rempos) {
        steps += 2 * remneg;
        steps += rempos;
      } else {
        steps += 2 * rempos;
        steps += remneg;
      }
      cout << steps << '\n';
    }
    return 0;
}
