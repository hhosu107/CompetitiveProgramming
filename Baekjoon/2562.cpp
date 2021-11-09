#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> argmax(int (&a)[9], int n){
  int max = -1, arg = 0;
  for(int i=0; i<n; i++){
    if (max < a[i]){
      max = a[i];
      arg = i + 1;
    }
  }
  return make_pair(max, arg);
}

int main(){
  int a[9];
  for(int i=0; i<9; i++){
    cin >> a[i];
  }
  pair<int, int> ret = argmax(a, 9);
  cout << ret.first << endl << ret.second << endl;
  return 0;
}
