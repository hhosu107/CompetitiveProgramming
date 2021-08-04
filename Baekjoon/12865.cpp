#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int dp[101][100001];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> prods = vector<pair<int, int>>(n+1);
  for(int i=1; i<=n; i++)
    cin >> prods[i].first >> prods[i].second;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=m; j++){
      dp[i][j] = dp[i-1][j];
      if (prods[i].first <= j)
        dp[i][j] = max(prods[i].second + dp[i-1][j - prods[i].first], dp[i][j]);
    }
  }
  cout << dp[n][m] << '\n';
  return 0;
}
