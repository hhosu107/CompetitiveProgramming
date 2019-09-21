#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main() {
  int white[4], black1[4], black2[4];
  for(int i=0; i<4; i++){
    scanf("%d", &white[i]);
  }
  for(int i=0; i<4; i++){
    scanf("%d", &black1[i]);
  }
  for(int i=0; i<4; i++){
    scanf("%d", &black2[i]);
  }
  bool covered = false;
  if(black1[1] <= white[1] && black1[3] >= white[3]){
    white[0] = (black1[2] > white[0] && black1[0] <= white[0] ? black1[2] : white[0]);
    white[2] = (black1[0] < white[2] && black1[2] >= white[2] ? black1[0] : white[2]);
  }
  if(black1[0] <= white[0] && black1[2] >= white[2]){
    white[1] = (black1[3] > white[1] && black1[1] <= white[1] ? black1[3] : white[1]);
    white[3] = (black1[1] < white[3] && black1[3] >= white[3] ? black1[1] : white[3]);
  }
  if(white[0] >= white[2] && white[1] >= white[3]) covered = true;
  if(!covered){
    if(black2[1] <= white[1] && black2[3] >= white[3]){
      white[0] = (black2[2] > white[0] && black2[0] <= white[0] ? black2[2] : white[0]);
      white[2] = (black2[0] < white[2] && black2[2] >= white[2] ? black2[0] : white[2]);
    }
    if(black2[0] <= white[0] && black2[2] >= white[2]){
      white[1] = (black2[3] > white[1] && black2[1] <= white[1] ? black2[3] : white[1]);
      white[3] = (black2[1] < white[3] && black2[3] >= white[3] ? black2[1] : white[3]);
    }
  }
  if(white[0] >= white[2] && white[1] >= white[3]) covered = true;
  if(covered) printf("NO\n");
  else printf("YES\n");
  return 0;
}
