#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int T;
  int input;
  cin >> T;
  for(int i=0; i<T; i++){
    cin >> input;
    int base = 2;
    int output = 0;
    bool flag = false;
    while(base <= 64){
      output = 0;
      for(int i=input; i>=1; i/=base){
        output = output * base + (i % base);
      }
      if(input == output){
        flag = true;
        break;
      }
      base++;
    }
    cout << flag << endl;
  }
  return 0;
}
