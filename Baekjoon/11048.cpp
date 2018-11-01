#include<iostream>
#include<algorithm>
using namespace std;

int lab[1000][1000];
int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      scanf("%d", &lab[i][j]);
  for(int j=1; j<M; j++)
    lab[0][j] += lab[0][j-1];
  for(int i=1; i<N; i++){
    lab[i][0] += lab[i-1][0];
    for(int j=1; j<M; j++){
      lab[i][j] += max(max(lab[i-1][j-1], lab[i-1][j]), lab[i][j-1]);
    }
  }
  printf("%d\n", lab[N-1][M-1]);
  return 0;
}
