#include<string>
#include<algorithm>
#include<functional>
#include<cctype>
#include<iostream>
using namespace std;
int contained;
int main(){
  int m;
  cin >> m;
  string op;
  int index;
  for(int i=0; i<m; i++){
    cin >> op;
    if(op.compare("add") == 0){
      cin >> index;
      contained = contained | (1 << index);
    }
    else if(op.compare("remove") == 0){
      cin >> index;
      contained == contained & (-1 ^ (1 << index));
    }
    else if(op.compare("check") == 0){
      cin >> index;
      cout << (contained >> index) & (1) << endl;
    }
    else if(op.compare("toggle") == 0){
      cin >> index;
      contained = contained ^ (1 << index);
    }
    else if(op.compare("all") == 0){
      contained = -1;
    }
    else if(op.compare("empty") == 0){
      contained = 0;
    }
  }
  return 0;
}
