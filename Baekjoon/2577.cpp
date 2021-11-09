#include<iostream>
using namespace std;

int main(){
  int digits[10] = {0};
  int a, b, c;
  cin >> a >> b >> c;
  int res = a * b * c;
  while(res > 0){
    int rem = res % 10;
    digits[rem]++;
    res /= 10;
  }
  for(int i=0; i<10; i++)
    cout << digits[i] << endl;
  return 0;
}
