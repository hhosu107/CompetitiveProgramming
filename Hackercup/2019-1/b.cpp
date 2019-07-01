#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

/* Input: T, for each test case, N, K, length N string that consists of A or B.
 * Goal: change existence of B smaller than or equal to K.
 * 1<=T<=500, 2<=N<=5000*/
int main() {
  int T, N, K;
  scanf("%d", &T);
  for(int t=1; t<=T; t++){
    string v;
    int ac = 0, bc = 0;
    vector<int> bs = vector<int>();
    bs.push_back(0);
    scanf("%d %d", &N, &K);
    cin >> v;
    for(int i=0; i<N; i++){
      if(v[i] == 'B'){
        bs.push_back(i+1);
        bc++;
      } else {
        ac++;
      }
    }
    printf("Case #%d: ", t);
    if(bc <= K){
      printf("0\n");
      continue;
    }
    int cost = 0, curr = 1;
    int size = bs.size();
    for(int i=0; i<size-1-K; i++){
      for(int j=0; j<bs[i+1]-bs[i]; j++){
        curr *= 2;
        curr %= 1000000007;
      }
      cost += curr;
      cost %= 1000000007;
    }
    printf("%d\n", cost);
  }
  return 0;
}
