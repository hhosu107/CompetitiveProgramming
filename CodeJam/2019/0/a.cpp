#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main(){
  int T;
  string N;
  cin >> T;
  for(int t = 1; t <= T; t++){
  cin >> N;
  cout << "Case #" << t << ": ";
  vector<int> A = vector<int>(N.length());
  vector<int> B = vector<int>(N.length());
  for(int i=N.length()-1; i>=0; i--){
    if (N[i] == '4'){
      A[i] = B[i] = 2;
    }
    else{
      A[i] = N[i] - '0';
      B[i] = 0;
    }
  }
  int leadingzero = 0;
  while(A[leadingzero] == 0) leadingzero++;
  for(int i=leadingzero; i < N.length(); i++) cout << A[i];
  cout << ' ';
  leadingzero = 0;
  while(B[leadingzero] == 0) leadingzero++;
  for(int i=leadingzero; i < N.length(); i++) cout << B[i];
  cout << endl;
  }
  return 0;
}
