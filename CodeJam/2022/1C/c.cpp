#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;

/* C
machines 1 ~ M, direct link of pair with priority 1 ~ M * (M - 1) / 2.
routing algorithm: aggresive, i.e., will route all traffic
from a machine through the highest priority link connected to it.
It makes some groups of machines isolated from others.
Machine m uses a link l iff l is the highest priority link connected to m.
Link is active if it is used by at least one of the two machines it connects.
Given the link priorities, the original network becomes partitioned into disjoint intranets.
Two machines belong to the same intranet iff there is some path btwn them using only active links.
Now investigate the extent of the problem
Interested in knowing probability of there being exactly K intranets
if the priorities are assigned uniformly at random from among the (M * (M - 1) / 2)! ways.
Input for each case: M, K. 1<=K<=M/2. represent it as p/q, gcd(p, q) = 1, i.e., p*q^-1 mod (10^9 + 7).
*/
int main(){
  int ans, N;
  int T;
  scanf("%d", &T);
  while(T--) {
    bool failed = false;
    bitset<8> x;
    for(int tr=0; tr<300; tr++) {
      x = bitset<8>(tr);
      cout << x << endl;
      scanf("%d", &ans);
      if (ans == 0) {
        break;
      } else if (ans == -1) {
        failed = true;
        break;
      }
    }
    if (failed) break;
  }
  return 0;
}
