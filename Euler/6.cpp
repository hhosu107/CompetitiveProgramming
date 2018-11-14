/* 6. compute (1 + ... + n)^2 - (1^2 + ... + n^2) */
#include<cstdio>
int diff(int n){
  return (((n+1)*n)/2)*(((n+1)*n)/2) - (2*n+1)*(n+1)*n/6;
}
int main(){
  printf("%d\n", diff(100));
  return 0;
}
