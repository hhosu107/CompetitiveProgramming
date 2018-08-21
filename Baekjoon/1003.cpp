#include<cstdio>
int T, N;
int main(){
  scanf("%d", &T);
  for(int i=0; i<T; i++){
    scanf("%d", &N);
    int a=0, b=1;
    if(N == 0) printf("1 0\n");
    else{
      for(int i=2; i<=N; i++){
        int temp = a+b;
        a = b;
        b = temp;
      }
      printf("%d %d\n", a, b);
    }
  }
  return 0;
}
