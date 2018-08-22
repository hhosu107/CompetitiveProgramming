#include<cstdio>
int gcd(int u, int d){
  if(d % u == 0) return u;
  else return gcd(d % u, u);
}
int main(){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int up = a * d + b * c;
  int down = b * d;
  int gc = (up < down ? gcd(up, down) : gcd(down, up));
  printf("%d %d\n", up/gc, down/gc);
  return 0;
}
