#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int T;
  string s;
  cin >> T;
  for(int t=1; t<=T; t++){
    //fflush(stdin);
    //cin.clear();
    cin >> s;
    int depth = 0;
    cout << "Case #" << t << ": ";
    for(char c : s){
      int cv = c - '0';
      int dd = cv - depth;
      if(dd > 0){
        for(int i=0; i<dd; i++)
          cout << '(';
      } else {
        for(int i=0; i<-dd; i++){
          cout << ')';
        }
      }
      cout << c;
      depth = cv;
    }
    for(int i=0; i<depth; i++)
      cout << ')';
    cout << endl;
  }
  return 0;
}
