#include<cstdio>
#include<iostream>
using namespace std;
int R, G;
int gc;
// put r >= g
int gcd(int r, int g){
  if(r % g == 0) return g;
  else return gcd(g, r%g);
}
int prime[80000];
int main(){
  return 0;
}
