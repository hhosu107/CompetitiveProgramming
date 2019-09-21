#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstdio>
using namespace std;

int xorseq[4][3] = {{0, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
int main(){
  int T, a, b, n;
  cin >> T;
  for(int i=1; i<=T; i++){
    cin >> a >> b >> n;
    int twop = 1, xorres = 0;
    for(int i=0; a>0||b>0; i++,a/=2,b/=2){
      xorres += twop * xorseq[(a%2)*2+(b%2)][n%3];
      twop *= 2;
    }
    cout << xorres << endl;
  }
  return 0;
}
