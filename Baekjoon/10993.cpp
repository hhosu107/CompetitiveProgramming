#include<bits/stdc++.h>
using namespace std;
char star[1025][2049];
int main(){
  int n;
    int center;;
  scanf("%d", &n);
  if(n==1) {
    printf("*\n");
  }
  else{
    center = pow(2, n-1)-1;
    for(int i=0; i<1024; i++){
      for(int j=0; j<2048; j++){
        star[i][j] = ' ';
      }
    }
    star[center][2*center] = '*';
    int power2 = 1;
    for(int i=1; i<n; i++){
      power2 *= 2;
      if(i % 2 == 1){
        for(int j=2*(center - (power2-1)); j<=2*(center + (power2-1)); j++){
          star[center-(power2-1)][j] = '*';
        }
        for(int j=1; j <= 2*(power2-1); j++){
          star[j+(center-(power2-1))][j+(center-(power2-1))] = star[j+(center-(power2-1))][2*(center) + 2*(power2-1) - j] = '*';
        }
      }
      else{
        for(int j=2*(center - (power2-1)); j<=2*(center + (power2-1)); j++){
          star[center+(power2-1)][j] = '*';
        }
        for(int j=1; j <= 2*(power2-1); j++){
          star[-j+(center+(power2-1))][j+(center-(power2-1))] = star[-j+(center+(power2-1))][2*(center) + 2*(power2-1) - j] = '*';
        }
      }
    }
    if(n % 2 == 0){
      for(int i=0; i<2*center+1; i++){
        for(int j=0; j<4*center+1-i; j++){
          printf("%c", star[i][j]);
        }
        printf("\n");
      }
    }
    else{
      for(int i=0; i<2*center+1; i++){
        for(int j=0; j<2*center+i; j++){
          printf("%c", star[i][j]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
