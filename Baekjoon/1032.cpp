#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
char pattern[52];
char candidate[52];
int N;
int main(){
  cin >> N;
  cin >> pattern;
  int len = strlen(pattern);
  for(int i=1; i<N; i++){
    cin >> candidate;
    for(int j=0; j<len; j++){
      if(pattern[j] != candidate[j])
        pattern[j] = '?';
    }
  }
  cout << pattern << endl;
  return 0;
}
