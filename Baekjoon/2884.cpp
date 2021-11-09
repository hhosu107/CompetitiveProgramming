#include<iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if (b < 45) a--;
  b = (b + 15) % 60;
  a = (a + 24) % 24;
  cout << a << " " << b << endl;
  return 0;
}
