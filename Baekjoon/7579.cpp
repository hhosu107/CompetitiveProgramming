#include<bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> mem(n);
  vector<int> recover_mem(n);
  for(auto &me: mem)
    cin >> me;
  for(auto &me: recover_mem)
    cin >> me;
  vector<vector<int>> dp(n+1, vector<int>(100 * n + 1));
  for(int i=0; i<n; i++) {
    for(int j=0; j<=100*n; j++) {
      dp[i+1][j] = dp[i][j]; // i번째까지 memory의 최소값은 i-1번째까지 쓴 경우
      if (recover_mem[i] <= j) {
        // i번째를 해제하기 전의 cost (j-recover_mem[i])에서의 최대 메모리와,
        // i번째를 해제하면서 얻는 memory의 합을 dp[i][j]와 비교.
        dp[i+1][j] = max(dp[i+1][j], dp[i][j-recover_mem[i]] + mem[i]);
      }
    }
  }
  for(int i=0; i<=100*n; i++) {
    if (dp[n][i] >= m) { // i의 cost로 m 이상의 memory를 해제했는가?
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}
