#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
using namespace std;


using ll = long long;

int main(){
  //std::ios_base::sync_with_stdio(false);
  //std::cin.tie(nullptr);
  //std::cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int n, p;
    cin >> n >> p;
    vector<vector<ll>> pr_minmax(n, vector<ll>(2));
    for(int i=0; i<n; i++) {
      pr_minmax[i][0] = 2147483647;
      pr_minmax[i][1] = -2147483648;
    }
    ll temp;
    for(int i=0; i<n; i++) {
      for(int j=0; j<p; j++) {
        cin >> temp;
        pr_minmax[i][0] = min(pr_minmax[i][0], temp);
        pr_minmax[i][1] = max(pr_minmax[i][1], temp);
      }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    ll last_maxmin[2] = {0, 0};
    for(int i=1; i<=n; i++) {
      ll increasing_mins[2], decreasing_mins[2];
      increasing_mins[0] = dp[i-1][0] + abs(last_maxmin[0] - pr_minmax[i-1][0]) + (pr_minmax[i-1][1] - pr_minmax[i-1][0]);
      increasing_mins[1] = dp[i-1][1] + abs(last_maxmin[1] - pr_minmax[i-1][0]) + (pr_minmax[i-1][1] - pr_minmax[i-1][0]);
      dp[i][0] = min(increasing_mins[0], increasing_mins[1]);
      decreasing_mins[0] = dp[i-1][0] + abs(last_maxmin[0] - pr_minmax[i-1][1]) + (pr_minmax[i-1][1] - pr_minmax[i-1][0]);
      decreasing_mins[1] = dp[i-1][1] + abs(last_maxmin[1] - pr_minmax[i-1][1]) + (pr_minmax[i-1][1] - pr_minmax[i-1][0]);
      dp[i][1] = min(decreasing_mins[0], decreasing_mins[1]);
      last_maxmin[0] = pr_minmax[i-1][1];
      last_maxmin[1] = pr_minmax[i-1][0];
    }
    cout << "Case #" << t << ": ";
    cout << min(dp[n][0], dp[n][1]) << endl;
  }
  return 0;
}
