#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int T;
  long long int input;
  cin >> T;
  for(int i=0; i<T; i++){
    cin >> input;
    long long int base;
    cin >> base;
    long long int output = 0;
    for(long long int i=input; i>=1LL; i/=base){
      output = output * base + (i % base);
    }
    if(input == output){
      cout << 1 << endl;
    }
    else cout << 0 << endl;
  }
  return 0;
}
