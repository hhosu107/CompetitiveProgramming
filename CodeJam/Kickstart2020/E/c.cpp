#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
using namespace std;

/* C. Toys
 * Circular queue; length of N toys.
 * Each toy has E_i, R_i. E_i is the time that kid enjoys i-th toy. After E_i
 * minutes, kid moves immediately to the next (if i == N, 1) toy.
 * R_i is the forgetting time that kid forget the i-th toy after having play it.
 * If kid meets that same toy before he forgets, he cry immediately and that's
 * the bad end.
 * Given the description of the toys, remove the smallest possible number of
 * them in order to make the kid play either and indefinitely long time or as
 * long as possible before he cries.
 * Small: N = 12
 * Large: N <= 10^5.
 * 1<=T<=100, 1<=E_i<=10^9, 1<=R_i<=10^9.
 * sol) If removing them is not possible to make indefinite time, then the cycle
 * stops within 2 full cycle (since, he stops at the second meet of the
 * troublesome toy).
 * small: make N times of loop(recursion) and collect all kinds of result.
 * large: throw.
 */
// Try small

typedef long long ll;

pair<ll, ll> lloop(vector<ll> &e, vector<ll> &r, vector<int> exc, int len, int idx, int num_exc) {
  if (idx == len) {
    // TODO(chansupark): write down.
    if(num_exc == len) {
      return make_pair((ll)num_exc, 0L);
    }
    int first_toy;
    for(int i=0; i<len; i++){
      if(exc[i] == 0){
        first_toy = i;
        break;
      }
    }
    ll loop_enjoy = 0;
    ll max_enjoy = 0;
    for(int i=0; i<len; i++){
      if (exc[i] == 0){
        loop_enjoy += e[i];
      }
    }
    max_enjoy = loop_enjoy;
    int last_toy = first_toy;
    for(; last_toy < len; last_toy++){
      if(exc[last_toy] != 0) continue;
      if(r[last_toy] <= loop_enjoy - e[last_toy]) {
        max_enjoy += e[last_toy];
      } else break;
    }
    if (last_toy == len) {
      return make_pair(num_exc, -1L);
    } return make_pair(num_exc, max_enjoy);
  } else {
    exc[idx] = 0;
    pair<ll, ll> left = lloop(e, r, exc, len, idx+1, num_exc);
    exc[idx] = 1;
    pair<ll, ll> right = lloop(e, r, exc, len, idx+1, num_exc+1);
    if(left.second == -1L && right.second == -1L) {
      return (left.first < right.first ? left : right);
    } else if(left.second == -1) {
      return left;
    } else if(right.second == -1) {
      return right;
    } else {
      if (left.second == right.second) {
        return (left.first < right.first ? left : right);
      }
      return (left.second > right.second ? left : right);
    }
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T, N, K;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N;
    vector<ll> e = vector<ll>(N, 0L);
    vector<ll> r = vector<ll>(N, 0L);
    for(int i=0; i<N; i++){
      cin >> e[i] >> r[i];
    }
    vector<int> exc = vector<int>(N, 0);
    pair<ll, ll> answer = lloop(e, r, exc, N, 0, 0);
    cout << "Case #" << t << ": " << answer.first << " ";
    if (answer.second == -1) {
      cout << "INDEFINITELY" << endl;
    } else cout << answer.second << endl;
  }
  return 0;
}
