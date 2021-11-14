#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
 * D. N events 1~N. prob. of occurrence of each event depends upon the
 * occurrence of exactly one other event called the parent event, except event
 * 1.
 * For 2~N, P_i (parent event), A_i (prob. of occurrence if P_i occurs),
 * B_i (prob. of occurrence if P_i does not occur).
 * For 1, K (occurrence prob).
 * Q queries consisting of u_j, v_j; Find the probability that both events u_j
 * and v_j have occurred.
 * Sol) Since there is no cycle (tree structure), The computation gets downways.
 * For given P_i, A_i * 10^6, B_i * 10^6 and K * 10^6,
 * print each R_i = p_i / q_i and print it as p_i q_i where R_i * q_i === p mod
 * (10^9 + 7) exactly. Since there is no cycle, R_j exists and uniquely
 * determined.
 * Sol) compute each with mod 10^9+7 exactly.
 * Sol) if u_j and v_j are not direct ancestor-childrens, find the common root;
 * compute common roots' on/off rate, compute below from that common ancestor.
 * and compute by that.
 * Otherwise, find ancestor's occurrence rate; compute childs by assuming that
 * ancester is already turned on... last, find child's occurrence rate.
 * depending on ...
 */
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    cout << "Case #" << t << ": " << '\n';
  }
  return 0;
}
