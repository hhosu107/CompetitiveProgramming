/* Compute 10001th prime */
#include<cstdio>
long long int prime[11111];
int main(){
  prime[0] = 2;
  int index = 1;
  for(long long int i=3; index < 10001; i+=2){
    bool flag = false;
    for(int d=0; prime[d] * prime[d] <= i; d++){
      if(i % prime[d] == 0){
        flag = true;
        break;
      }
    }
    if(!flag) prime[index++] = i;
  }
  printf("%lld\n", prime[10000]);
  return 0;
}
