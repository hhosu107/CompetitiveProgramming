#include<cstdio>
#include<iostream>
using namespace std;

int main(){
  int maxi=-2147483648, mini=2147483647, cand;
  int C, N;
  cin >> C;
  for(int i=0; i<C; i++){
    cin >> cand;
    if(maxi < cand) maxi = cand;
    if(mini > cand) mini = cand;
  }
  cout << maxi * mini << endl;
  return 0;
}
