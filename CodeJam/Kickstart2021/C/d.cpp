#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* D. Valid arithmetic expressions using non-neg integers, (), +, *, #.
 * # can be any total function, and this expression is fully infix.
 * Fully parenthesized: every operator/operands are wrapped in a single
 * parenthesis.
 * Group the expressions into equivalence classes.
 * Note: x#y cannot be equivalated with any other expression except itself.
 * Sol) Hmm... generate an infix calculator and let # free.
 * Problem: x#y != y#x in general.
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
