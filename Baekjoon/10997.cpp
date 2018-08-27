#include<cstdio>
#include<iostream>
using namespace std;
char star[400][400];
int main(){
  int n;
  scanf("%d", &n);
  if(n==1) {
    printf("*\n");
  }
  else{
    for(int i=0; i<4*(n-1)+3; i++){
      for(int j=0; j<4*(n-1)+1; j++){
        star[i][j] = ' ';
      }
    }
    star[2*n-2][2*n-2] = star[2*n-1][2*n-2] = star[2*n][2*n-2] = '*';
    for(int i=1; i<n; i++){
      for(int j=2*((n-1)-i); j<=2*((n-1)+i); j++)
        star[2*((n-1)-i)][j] = star[2*((n-1)+i)+2][j] = star[j+1][2*((n-1)-i)] = star[j+1][2*((n-1)+i)] = '*';
      star[2*((n-1)-i)+1][2*((n-1)+i)] = ' ';
      star[2*(n-i)][2*((n-1)+i)-1] = '*';
    }
    for(int i=0; i<4*(n-1)+1; i++)
      printf("*");
    printf("\n*\n");
    for(int i=2; i<4*(n-1)+3; i++){
      for(int j=0; j<4*(n-1)+1; j++){
        printf("%c", star[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
