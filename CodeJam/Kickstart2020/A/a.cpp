#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/* A.
 * N houses, A_i dollars, budget of B dollars.
 * Max number of houses to buy?
 */
int T, N, B;
int a[100000];
  
int knapSack(){
  vector<vector<int>> k = vector<vector<int>>(N+1, vector<int>(B+1));
  for (int i = 0; i <= N; i++){
    for (int w = 0; w <= B; w++){
      if (i == 0 || w == 0)
        k[i][w] = 0;
      else if (a[i-1] <= w)
        k[i][w] = (1 + k[i-1][w-a[i-1]] < k[i-1][w] ? k[i-1][w] : 1 + k[i-1][w-a[i-1]]);
      else
        k[i][w] = k[i-1][w];
    }
  }
  return k[N][B]; 
} 
  
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> N >> B;
    for(int i=0; i<N; i++)
      cin >> a[i];
    cout << "Case #" << t << ": " << knapSack() << endl;
  }
  return 0;
}
