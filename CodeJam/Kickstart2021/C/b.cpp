#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/* B. Sol) G = (j+1)(j/2 + K). Can we find j?
 * 1) j even: (2l + 1)(l+K)
 * 2) j odd: (j+1)/2 * (j+2K).
 * 3) j starts at 0.
 * Sol) Compute primes up to 2000000.
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
