#include<bits/stdc++.h>
using namespace std;

/* 2. Subset of {1, ..., N}; subset of {1, ..., N} that did not taken by the
 * previous subset.
 * Magic ratio X : Y.
 * Choose the subset with the exact ratio X : Y. Is it possible?
 * Sol) If (X + Y) divides (N) * (N+1) / 2, it is possible.
 * Why?
 * 1 ~ N can be achieved by selecting 1 ~ N.
 * From that on, we can select
 * N + 1 ~ N + (N - 1) by selecting N and 1 ~ N-1.
 * N + (N-1) + 1 ~ N + (N-1) + (N - 2) by selecting N, N-1 and 1 ~ N-2.
 * ...
 * N + ... + 2 by selecting N, N-1, ..., 2.
 */

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  int N, X, Y;
  for(int t=1; t<=T; t++) {
    cin >> N >> X >> Y;
    cout << "Case #" << t << ": ";
    if (((N + 1) * N / 2) % (X + Y) != 0) {
      cout << "IMPOSSIBLE" << '\n';
      continue;
    } else {
      cout << "POSSIBLE" << '\n';
      int asum = ((N + 1) * N / 2) / (X + Y) * X;
      int bsum = ((N + 1) * N / 2) / (X + Y) * Y;
      vector<bool> ataken(N + 1, false);
      int arem = asum;
      int ataken_cnt = 0;
      for(int i=N; i>=1; i--) {
        if (arem >= i) {
          arem -= i;
          ataken[i] = true;
          ataken_cnt++;
        } else {
          ataken[arem] = true;
          ataken_cnt = (arem == 0) ? ataken_cnt : ataken_cnt + 1;
          arem = 0;
          break;
        }
      }
      cout << ataken_cnt << '\n';
      for(int i=1; i<=N; i++) {
        if (ataken[i]) {
          cout << i << ' ';
        }
      }
      cout << '\n';
    }
  }
  return 0;
}
