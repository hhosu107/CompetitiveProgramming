#include<iostream>
using namespace std;

int N;
int cand;
int spin[1000][1000];

int main(){
  int x, y;
  int dx, dy;
  cin >> N;
  cin >> cand;
  spin[(x=(N+1)/2)][(y=(N+1)/2)] = 1;
  int point = 2;
  int width = 0;
  while(point <= N * N){
    x -= 1;
    width += 2;
    for(int i=0; i<width; i++){
      spin[x][y] = point;
      if(point == cand){
        dx = x; dy = y;
      }
      point++;
      y++;
    }
    y--; x++;
    for(int i=0; i<width; i++){
      spin[x][y] = point;
      if(point == cand){
        dx = x; dy = y;
      }
      point++;
      x++;
    }
    x--; y--;
    for(int i=0; i<width; i++){
      spin[x][y] = point;
      if(point == cand){
        dx = x; dy = y;
      }
      point++;
      y--;
    }
    y++; x--;
    for(int i=0; i<width; i++){
      spin[x][y] = point;
      if(point == cand){
        dx = x; dy = y;
      }
      point++;
      x--;
    }
    x++;
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      cout << spin[i][j] << ' ';
    }
    cout << endl;
  }
  cout << dx << ' ' << dy << endl;
  return 0;
}
