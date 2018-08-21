#include<cstdio>
#include<cstring>
#include<cstdlib>
char eight[333336];
int main(){
  scanf("%s", eight);
  if(eight[0] == '0')
    printf("0\n");
  else{
    int len = strlen(eight);
    if(eight[0]-'0' >= 4) printf("1");
    if(((eight[0]-'0')/2)%2 == 1) printf("1");
    else if((eight[0]-'0') >= 2) printf("0");
    if((eight[0]-'0')%2 == 1) printf("1");
    else printf("0");
    for(int i=1; i<len; i++){
      printf("%c%c%c", (eight[i] - '0')/4+'0', ((eight[i]-'0')/2)%2+'0', (eight[i]-'0')%2+'0');
    }
    printf("\n");
  }
  return 0;
}
