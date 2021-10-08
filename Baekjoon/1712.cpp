#include<cstdio>
long long int A, B, C;
int main(){
  scanf("%lld %lld %lld", &A, &B, &C);
  if (B >= C) {
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", (A / (C - B)) + 1);
  return 0;
}
