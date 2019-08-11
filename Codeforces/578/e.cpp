#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;
int largest_presuf(const string &str, int minlen){
  int n = str.length();
  if(n < 2) {
    return 0;
  }
  int len = 0;
  int i = n - minlen;
  while(i < n){
    if(str[i] == str[len]){
      ++len;
      ++i;
    } else{
      if(len == 0){
        ++i;
      } else {
        --len;
      }
    }
    if(len == minlen){
      return len;
    }
  }
  return len;
}
int main(){
  int n;
  vector<string> words;
  cin >> n;
  words = vector<string>(n);
  for(int i=0; i<n; i++){
    cin >> words[i];
  }
  string concat = words[0];
  for(int i=1; i<n; i++){
    string presuf = words[i] + concat;
    int minlen = min(words[i].length(), concat.length());
    int common = largest_presuf(presuf, minlen);
    concat += words[i].substr(common);
  }
  printf("%s\n", concat.c_str());
  return 0;
}
