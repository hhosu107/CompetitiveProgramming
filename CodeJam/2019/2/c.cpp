#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; t++){
    int N;
    cin >> N;
    vector<int> C = vector<int>(N);
    vector<int> J = vector<int>(N);
    for(int i=0; i<N; i++)
      cin >> C[i] >> J[i];
    int c, j;
    bool flag = true;
    for(c=1; c<=100; c++){
      for(j=1; j<=100; j++){
        flag = true;
        for(int i=1; i<N; i++){
          if(c*C[i-1] + j*J[i-1] >= c*C[i] + j*J[i]){
            flag = false;
            break;
          }
        }
        if(flag == true) break;
      }
      if(flag == true) break;
    }
    cout << "Case #" << t << ": ";
    if (flag == true) {
      cout << c << " " << j << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}
