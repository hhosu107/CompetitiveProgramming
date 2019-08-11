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
int main(){
  vector<int> occ(10);
  int N;
  string e;
  cin >> N;
  cin >> e;
  for(char c : e){
    switch(c){
      case 'L':
        for(int i=0; i<10; i++){
          if(occ[i] == 0){
            occ[i] = 1;
            break;
          }
        }
        break;
      case 'R':
        for(int i=9; i>=0; i--){
          if(occ[i] == 0){
            occ[i] = 1;
            break;
          }
        }
        break;
      default:
        occ[c - '0'] = 0;
        break;
    }
  }
  for(int r : occ){
    cout << r;
  }
  cout << '\n';
  return 0;
}
