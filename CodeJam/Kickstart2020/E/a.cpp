#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* A.
 * Arithmetic Array: contains at least two integers, differences between
 * consecutive integers are equal. [9, 10], [3, 3, 3], [9, 7, 5, 3] as ex.
 * There are N non-neg integers, ith as A_i.
 * Choose contiguous arithmetic subarray from array with max length.
 */
int a[200000];
int T, N;
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N;
    for(int i=0; i<N; i++)
      cin >> a[i];
    int max_len = 2;
    int diff = a[1] - a[0];
    int len = 2;
    for(int i=2; i<N; i++){
      if(a[i] - a[i-1] != diff){
        if(max_len < len) max_len = len;
        diff = a[i] - a[i-1];
        len = 2;
      } else {
        len++;
      }
    }
    if(max_len < len) max_len = len;
    cout << "Case #" << t << ": " << max_len << endl;
  }
  return 0;
}
