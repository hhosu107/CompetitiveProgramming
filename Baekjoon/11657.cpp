#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
/* 11657: Bellman-Ford Algorithm with negative-cycle check */
typedef struct weight{
  int s;
  int w;
}weight;
vector<vector<weight>> dist;
vector<vector<int>> dp;
/* Bellman-Ford works as this:
 * for each k, for each edge (u, v), d(k, v) = min(d(k, v), d(k-1, u) + cost(u, v));
 * In other words, when we accept the input for the edge (u, v, weight), save this edge at dist[v] as push_back(pair<int, int>(u, weight)).
 */
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  dist = vector<vector<weight>>(n, vector<weight>());
  int s, d, w;
  weight we;
  for(int i=0; i<m; i++){
    scanf("%d %d %d", &s, &d, &w);
    we.s = s-1;
    we.w = w;
    dist[d-1].push_back(we);
  }
  dp = vector<vector<int>>(n, vector<int>(n, 50000000));
  dp[0][0] = 0;
  for(int k=1; k<n; k++){
    for(int i=0; i<n; i++)
      dp[k][i] = dp[0][i]; // Cache-friendly
    for(int i=0; i<n; i++){
      for(auto edge : dist[i]){
        if(dp[k-1][edge.s] != 50000000){
          dp[k][i] = min(dp[k][i], dp[k-1][edge.s] + edge.w);
        }
      }
    }
  }
  // Now check the negative cycle
  bool negCy = false;
  for(int i=0; i<n; i++){
    for(auto edge : dist[i]){
      if(dp[n-1][edge.s] != 50000000 && dp[n-1][i] > dp[n-1][edge.s] + edge.w){
        negCy = true;
        break;
      }
    }
  }
  if(negCy){
    printf("-1\n");
  }
  else{
    for(int j=1; j<n; j++){
      if(dp[n-1][j] == 50000000) printf("-1\n");
      else printf("%d\n", dp[n-1][j]);
    }
  }
  return 0;
}
