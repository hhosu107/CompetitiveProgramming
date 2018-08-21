#include<iostream>
int T, A, B;
int gcd, lcm;
using namespace std;

int main(){
  cin >> T;
  for(int i=0; i<T; i++){
    cin >> A >> B;
    if(A < B){
      int temp = A;
      A = B;
      B = temp;
    }
    lcm = A * B;
    while(A % B != 0){
      int temp = B;
      B = A % B;
      A = temp;
    }
    cout << lcm / B << endl;
  }
  return 0;
}
