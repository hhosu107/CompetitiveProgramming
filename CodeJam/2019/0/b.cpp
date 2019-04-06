#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
  int T, N;
  string P;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N;
    cin >> P;
    cout << "Case #" << t << ": ";
    for(int i=0; i<P.length(); i++){
      cout << (P[i] == 'E' ? 'S' : 'E');
    }
    cout << endl;
  }
  return 0;
}
