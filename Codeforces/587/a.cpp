#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std;

char pref[200002];
int main() {
  int n;
  int cnt = 0;
  scanf("%d", &n);
  cin >> pref;
  for(int i=0; i<n; i+=2){
    if(pref[i] == pref[i+1]){
      pref[i+1] = (int)('a') + (int)('b') - (int)pref[i];
      cnt++;
    }
  }
  printf("%d\n%s\n", cnt, pref);
  return 0;
}

