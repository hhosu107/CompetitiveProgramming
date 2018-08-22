#include<cstdio>
#include<cstring>
#include<cstdlib>
char bi[1000002];
int len;
int main(){
  scanf("%s", bi);
  len = strlen(bi);
  if(bi[0] == '0') printf("0\n");
  else{
    int msl = len % 3;
    int msb = 0;
    for(int i=0; i<msl; i++){
      msb = 2 * msb + (bi[i] - '0');
    }
    if(msl != 0) printf("%d", msb);
    for(int i=msl; i<len; i+=3){
      printf("%d", (bi[i] - '0')*4 + (bi[i+1] - '0')*2 + (bi[i+2] - '0'));
    }
    printf("\n");
  }
  return 0;
}
