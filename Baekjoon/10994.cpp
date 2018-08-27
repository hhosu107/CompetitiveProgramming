#include<cstdio>
#include<iostream>
using namespace std;
char star[400][400];
int main(){
  int n;
  scanf("%d", &n);
  for(int i=0; i<4*(n-1)+1; i++){
    for(int j=0; j<4*(n-1)+1; j++){
      star[i][j] = ' ';
    }
  }
  for(int i=0; i<n; i++){
    for(int j=2*((n-1)-i); j<=2*((n-1)+i); j++)
      star[2*((n-1)-i)][j] = star[2*((n-1)+i)][j] = star[j][2*((n-1)-i)] = star[j][2*((n-1)+i)] = '*';
  }
  for(int i=0; i<4*(n-1)+1; i++){
    for(int j=0; j<4*(n-1)+1; j++){
      printf("%c", star[i][j]);
    }
    printf("\n");
  }
  return 0;
}
