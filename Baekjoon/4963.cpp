#include<iostream>
#include<cstdio>
using namespace std;

bool visited[50][50];
int island[50][50];
int main(){
  int w, h;
  cin >> w >> h;
  while(w * h != 0){
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        scanf("%d", &island[i][j]);
      }
    }
    int cnt = 0;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        // do dfs on island[i][j]; see 5 directions to approach.
      }
    }
    printf("%d\n", count);
  }
  return 0;
}
