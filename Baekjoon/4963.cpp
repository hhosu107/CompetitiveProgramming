#include<iostream>
#include<cstdio>
using namespace std;

bool visited[50][50];
int island[50][50];
int dxy[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
int dfs(int i, int j, int w, int h) {
  if (visited[i][j]) return 0;
  if (island[i][j] == 0) return 0;
  visited[i][j] = true;
  for(int k=0; k<8; k++) {
    int nx = i + dxy[k][0];
    int ny = j + dxy[k][1];
    if (nx >= 0 && nx < h && ny >= 0 && ny < w && island[nx][ny] == 1) {
      dfs(nx, ny, w, h);
    }
  }
  return 1;
}

int main(){
  int w, h;
  cin >> w >> h;
  while(w * h != 0){
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        scanf("%d", &island[i][j]);
        visited[i][j] = false;
      }
    }
    int sum = 0;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        int new_island = dfs(i, j, w, h);
        sum += new_island;
      }
    }
    printf("%d\n", sum);
    cin >> w >> h;
  }
  return 0;
}
