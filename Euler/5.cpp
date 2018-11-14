/* 5. Compute LCM of 1, 2, ..., 20 */

#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a, int b){
  if(a % b == 0) return b;
  else return gcd(b, a % b);
}
int main(){
  int lcm = 6;
  for(int i=4; i<=20; i++){
    lcm = lcm / gcd(lcm, i) * i;
  }
  cout << lcm << endl;
  return 0;
}
