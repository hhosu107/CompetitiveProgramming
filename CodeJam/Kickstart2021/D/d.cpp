#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* D. primes and queries
 * Given prime P, V(x): degree of P in the prime factorization of x, i.e., V(x) = y means x % P^y == 0, x % P^(y+1) != 0. V(0) = 0.
 * Array A = [A_i]. Process Q queries:
 * type 1: 1 pos val: assign a value val to the element at pos, i.e., A_pos = val
 * type 2: 2 S L R: print sum(i from L to R inclusive) V(A_i^S - (A_i mod P)^S).
 * Sol)
 * A_i^S - (A_i mod P)^S = (A_i - A_i mod P) * (A_i^(S-1) + ... + (A_i - mod P)^(S-1)).
 * Since P is prime, if A_i is not divisible by P, then V(blahblah) = V(A_i - A_i mod P).
 * Otherwise, ...
 * Since summation can be separated, we should update partial sums of V once right before the type2 query occurs.
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
