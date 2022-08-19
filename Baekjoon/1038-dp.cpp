#include<iostream>
using namespace std;

/* Sol)
 * If we have all integers with length l, how to construct all integers with
 * length l + 1 in increasing order?
 * Start from the lowest index that points the smallest integer with length l.
 * To construct length l + 1 integer, for 0 <= j < integer % 10, integer * 10 +
 * j is the next smallest number with length l + 1.
 * Thus, track that previous integer with index i, and save each integer with
 * other index e.
 * when e reaches the end, print that dp value.
 */

int main () {
  int l, e = 9;
  int dp[1024] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cin >> l;
  if (l == 1022) {
    cout << "9876543210" << endl;
    return 0;
  }
  if (l > 1022) {
    cout << "-1" << endl;
    return 0;
  }
  for(int i=0; e<l; i++) {
    for(int j=0; j<dp[i] % 10; j++)
      dp[++e] = dp[i] * 10 + j;
  }
  cout << dp[l] << endl;
  return 0;
}
