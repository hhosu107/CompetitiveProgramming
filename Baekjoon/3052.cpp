#include<iostream>
using namespace std;

int main(){
  int a[10];
  int rem[42] = {0};
  for(int i=0; i<10; i++) {
    cin >> a[i];
    rem[a[i] % 42]++;
  }
  int diffrems = 0;
  for(int i=0; i<42; i++){
    if (rem[i] > 0) diffrems++;
  }
  cout << diffrems << endl;
  return 0;
}

