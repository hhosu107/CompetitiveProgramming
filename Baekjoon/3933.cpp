#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

using ll = long long;

ll dp[5][33000] = {{0}};
ll m[33000] = {0};
ll count_possible_parts(int used_nums, int last_elem, int partial_sum, int target) {
  if (used_nums > 4)
    return 0;
  else if (partial_sum == target)
    return 1;
  else if (partial_sum > target)
    return 0;
  else {
    ll res = 0;
    for(int i=last_elem; i<=(int)(sqrt(target)) + 1; i++)
      res += count_possible_parts(used_nums + 1, i, partial_sum + i * i, target);
    return res;
  }
}

int main () {
  dp[0][0] = 1;
  for(int i=1; i<=4; i++) {
    for(int j=1; j<=32000; j++) {
      for(int k=1; k*k <= j; k++) {
        dp[i][j] += dp[i-1][j-k*k];
      }
    }
  }
  for(int i=1; i<=32000; i++) {
    for(int j=1; j<=4; j++) {
      m[i] += dp[j][i];
    }
  }
  int n;
  cin >> n;
  while(n != 0) {
    cin >> n;
    cout << m[n] << endl;
  }
  return 0;
}
