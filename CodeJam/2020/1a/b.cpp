#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* B. Pascal triangle: (r, 1) ~ (r, r) for 1<=r, (r, k) = (r-1, k-1) + (r-1, k)
 * (r1, k1) ~ (rs, ks): r1 = k1 = 1, (r_i+1, k_i+1) = one of (r_i - 1, k_i - 1), (r_i - 1, k_i), (r_i, k_i - 1), (r_i, k_i + 1), (r_i + 1, k_i),  (r_i + 1, k_i + 1), For every i != j, (r_i, k_i) != (r_j, k_j)
 * Find the walk of s<=500 positions such that the sum of numbers are equal to N.
 */

/* B-1: N<=501. Sol) 1, 1; 2, 1; 3, 1; 3, 2; 3, 3; 4, 4; ... */

void b1(int N) {
  if (N <= 4){
    for(int i=1; i<=N; i++){
      cout << i << " " << i << endl;
    }
  } else {
    cout << "1 1\n2 1\n3 1\n 3 2\n";
    for(int i=1; i<=N-5; i++){
      cout << i + 2 << " " << i + 2 << endl;
    }
  }
}

/* B-2: N<=1000. Sol) 1, 1; 2, 1; 3, 1; 3, 2; 4, 3; ... (some value that the partial sum differs less than the next i+1, 2); i, 1; ... */
void b2(int N) {
  if (N <= 4){
    for(int i=1; i<=N; i++){
      cout << i << " " << i << endl;
    }
  } else {
    cout << "1 1\n2 1\n3 1\n3 2\n";
    int n = N-5;
    if(n <= 2) {
      for(int i=1; i<=n; i++){
        cout << i + 2 << " " << i + 2 << endl;
      }
    } else {
      int i = 3;
      for(i=3;;i++){
        cout << i+1 << " " << 2 << endl;
        n -= i;
        if (n < i + 1) break;
      }
      for(int j=i; j<=i+n-1; j++){
        cout << j+1 << " " << 1 << endl;
      }
    }
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N;
  cin >> T;
  for(int i=1; i<=T; i++){
    cin >> N;
    cout << "Case #" << i << ":" << endl;
    b2(N);
  }
  return 0;
}
