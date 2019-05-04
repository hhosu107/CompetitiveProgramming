#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main(){

  // Our robot can always win iff our robot can defeat all others
  int T, A;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> A;
    vector<string> C = vector<string>(A);
    vector<bool> defeat = vector<bool>(A, false);
    for(int i=0; i<A; i++)
      cin >> C[i];
    cout << "Case #" << t << ": ";
    vector<char> sol = vector<char>(501);
    bool flag = false;
    int length;
    for(int i=0; i<500; i++){
      bool r = false, p = false, s = false;
      for(int j=0; j<A; j++){
        if(defeat[j]) continue; // If we defeat some, just exclude them
        int idx = i % C[j].length();
        if(C[j][idx] == 'R') r = true;
        else if(C[j][idx] == 'P') p = true;
        else if(C[j][idx] == 'S') s = true;
      }
      // We cannot defeat some robots at some step iff there are all of R P S (if we haven defeat them earlier)
      if(r && p && s) {
        break;
      }
      // If all other robots use same key, pick a winning key
      else if ( r && !p && !s ) {
        sol[i] = 'P';
        flag = true;
        length = i+1;
        break;
      }
      else if ( !r && p && !s ) {
        sol[i] = 'S';
        flag = true;
        length = i+1;
        break;
      }
      else if ( !r && !p && s ) {
        sol[i] = 'R';
        flag = true;
        length = i+1;
        break;
      }
      // If all other robots don't use some key, pick one key that draws or win
      else if ( !r && p && s ) {
        sol[i] = 'S';
        for(int j=0; j<A; j++){
          int idx = i % C[j].length();
          if (!defeat[j] && C[j][idx] == 'P') {
            defeat[j] = true;
          }
        }
      }
      else if ( r && !p && s ) {
        sol[i] = 'R';
        for(int j=0; j<A; j++){
          int idx = i % C[j].length();
          if (!defeat[j] && C[j][idx] == 'S') {
            defeat[j] = true;
          }
        }
      }
      else if ( r && p && !s ) {
        sol[i] = 'P';
        for(int j=0; j<A; j++){
          int idx = i % C[j].length();
          if (!defeat[j] && C[j][idx] == 'R') {
            defeat[j] = true;
          }
        }
      }
    }
    if(!flag) {
      cout << "IMPOSSIBLE";
    }
    else {
      for(int i=0; i<length; i++){
        cout << sol[i];
      }
    }
    cout << '\n';
  }
  return 0;
}
