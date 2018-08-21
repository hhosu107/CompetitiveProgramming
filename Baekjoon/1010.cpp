#include<iostream>
using namespace std;
int combi[30][30];
int main(){
  int T;
  combi[1][0] = combi[1][1] = combi[0][0] = 1;
  for(int i=2; i<30; i++){
    for(int j=0; j<=i; j++){
      if(j == 0 || j == i) combi[i][j] = 1;
      else combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
    }
  }
  scanf("%d", &T);
  for(int i=0; i<T; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", combi[y][x]);
  }
  return 0;
}
