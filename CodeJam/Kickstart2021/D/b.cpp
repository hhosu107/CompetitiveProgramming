#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/* B. Cutting intervals.
 * N intervals [l_i, r_i] that may not be unique.
 * Perform max C cuts that cut all intervals [L, R] for which L < X < R that cuts that interval to [L, X], [X, R].
 * Cuts cannot split the endpoint and must be done on the integer points.
 * Find max number of intervals that can be obtained thru a max C cuts.
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, K, N;
  cin >> T;
  for (int t=1; t<=T; t++){
    cout << "Case #" << t << ": ";
  }
  return 0;
}
