#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


/* B. N customers, each has P products to inflate.
 * Each has target pressure.
 * Can inflate products in any order but cannot change customer order.
 * Must inflate all of the products before do the next customer.
 * The problem: air pressure buttons can change only by 1 pascal per press.
 * How can minimize the number of buttons to be pressed?
 * Initial pressure = 0.
 */
using ll = long long;

/* Sol)
 * If n = 1, pressure = max(pressures).
 * But we have to adapt after that by watching next customer's pressure distrib.
 * Suppose ith customer has ended with pressure p_i.
 * suppose i+1th customer has min_pressure px_i+1 and max_pressure py_i+1.
 * Can we just stop p_i+1 as one of the min/max? I think we cannot.
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    cout << "Case #" << t << ": ";
  }
  return 0;
}
