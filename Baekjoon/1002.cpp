#include<cstdio>
int x1, y1, r1, x2, y2, r2, rsq;
int main(){
  int T;
  scanf("%d", &T);
  for(int i=0; i<T; i++){
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    if(x1 == y1 && x2 == y2){
      if(r1 != r2) printf("0\n");
      else printf("-1\n");
    }
    else{
      if((r1 + r2) * (r1 + r2) > (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) && (r1 - r2) * (r1 - r2) < (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) printf("2\n");
      else if((r1 + r2) * (r1 + r2) == (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) || (r1 - r2) * (r1 - r2) == (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) printf("1\n"); 
      else printf("0\n");
    }
  }
  return 0;
}
