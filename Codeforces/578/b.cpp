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
  int T;
  int n, m, k;
  int col[100];
  bool flag = true;
  cin >> T;
  for(int t=1; t<=T; t++){
    flag = true;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
      cin >> col[i];
    }
    int r = m;
    for(int i=0; i<n-1; i++){
      if(col[i] + k < col[i+1]){
        r -= (col[i+1] - k - col[i]);
        col[i] += (col[i+1] - k - col[i]);
      }
      else{
        int possible;
        if(col[i+1] >= k){
          possible = col[i] - (col[i+1] - k);
        } else {
          possible = col[i];
        }
        col[i] -= possible;
        r += possible;
      }
      if (r < 0){
        cout << "NO\n";
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "YES\n";
    }
  }
  return 0;
}
