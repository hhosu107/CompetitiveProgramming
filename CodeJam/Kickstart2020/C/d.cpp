#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
typedef long long ll;
/* D: ith elmt A_i is called sweetness value of ith candy.
 * Q operations (possibly 2 types):
 * - update the sweetness valye of candy.
 * - query the sweetness score of a subarray.
 *   subarray (l, r) sweetness = sum (-1)^(i-l)A_i * (i - l + 1) for all i from l to r inclusive.
 * How to find total sum of sweetness scores of all queries?
 * Sol) First, represent the subarray sweetness using a value of A[r+1] - A[l] (like subsum)*/

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  cin >> T;
  for(int t=1; t<=T; t++){
    cout << "Case #" << t << ": ";
  }
  return 0;
}
