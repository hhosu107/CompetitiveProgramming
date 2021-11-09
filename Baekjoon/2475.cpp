#include<iostream>
using namespace std;

int main(){
  int a[5];
  for(int i=0; i<5; i++)
    cin >> a[i];
  int checksum = 0;
  for(int i=0; i<5; i++)
    checksum += a[i] * a[i];
  cout << (checksum % 10) << endl;
  return 0;
}
