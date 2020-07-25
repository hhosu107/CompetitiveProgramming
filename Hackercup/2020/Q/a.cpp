#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
  int T, n;
  string infl, oufl;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for(int t=1; t<=T; t++) {
    cin >> n;
    cin >> infl;
    cin >> oufl;
    char avail[51] = "";
    cout << "Case #" << t << ":\n";
    for(int i=0; i<n; i++){
      avail[i] = 'Y';
      bool flag = true;
      for(int j=i-1; j>=0; j--){
        if(flag && (oufl[j+1] == 'Y' && infl[j] == 'Y')){
          avail[j] = 'Y';
        } else {
          flag = false;
          avail[j] = 'N';
        }
      }
      flag = true;
      for(int j=i+1; j<n; j++){
        if(flag && (oufl[j-1] == 'Y' && infl[j] == 'Y')){
          avail[j] = 'Y';
        } else {
          flag = false;
          avail[j] = 'N';
        }
      }
      cout << avail << endl;
    }
  }
  return 0;
}
