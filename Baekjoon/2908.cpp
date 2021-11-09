#include<iostream>
using namespace std;

int flip_and_answer(int a, int b) {
  int ra = 0;
  int rb = 0;
  while (a > 0 && b > 0){
    int rem;
    rem = a % 10;
    ra = 10 * ra + rem;
    a /= 10;
    rem = b % 10;
    rb = 10 * rb + rem;
    b /= 10;
  }
  return (ra < rb ? rb : ra);
}

int main(){
  int a, b;
  cin >> a >> b;
  cout << flip_and_answer(a, b) << endl;
  return 0;
}
