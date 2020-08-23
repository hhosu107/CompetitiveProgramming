#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/* B.
 * N office buildings, 1~N from left to right, height between 1~N.
 * A: leftmost of campus (left of 1) / B: rightmost of campus (right of N)
 * A: x is visible iff no building to the left of x that is strictly higher than
 * x. Vice versa for B.
 * A: there are A buildings that visible / B: there are B buildings that
 * visible. For both, C buildings are visible.
 * Given N, A, B, C, output any possible candidates of height, or "IMPOSSIBLE"
 * if there are no candidates.
 * Think...
 * Only the highest buildings are visible for both of them. Based on this,
 * arrange A and B.
 */
int T, N, A, B, C;
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N >> A >> B >> C;
    vector<int> highest = vector<int>(C, N);
    int ava = A - C, avb = B - C;
    cout << "Case #" << t << ":";
    if (ava + avb > N - C) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    } else if (ava == 0 && avb == 0) {
      if (C == 1 && N - C > 0) {
        cout << " IMPOSSIBLE" << endl;
      }
      else {
        for(int i=0; i<C-1; i++){
          cout << " " << N;
        }
        for(int i=0; i<N-C; i++){
          cout << " " << 1;
        }
        cout << " " << N << endl;
      }
      continue;
    } else {
      vector<int> lowest = vector<int>(N - C - ava - avb, 1);
      vector<int> a, b;
      a = vector<int>(ava, 0);
      for(int i=0; i<ava; i++){
        a[i] = N - ava + i;
      }
      b = vector<int>(avb, 0);
      for(int i=0; i<avb; i++){
        b[i] = N - i - 1;
      }
      for(int i: a){
        cout << " " << i;
      }
      if (ava > 0){
        for(int i: lowest) {
          cout << " " << i;
        }
        for(int i: highest){
          cout << " " << i;
        }
      } else {
        for(int i: highest) {
          cout << " " << i;
        }
        for(int i: lowest) {
          cout << " " << i;
        }
      }
      for(int i: b){
        cout << " " << i;
      }
      cout << endl;
    }
  }
  return 0;
}
