#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long int gcd(long long int a, long long int b){
  if(a % b == 0) return b;
  else return gcd(b, a % b);
}
long long int lcm(long long int &a, long long int &b){
  return a * b / gcd(a, b);
}
int main(){
  ios::sync_with_stdio(false);
  long long int a, b;
  cin >> a >> b;
  if(a < b) swap(a, b);
  long long int g = gcd(a, b);
  long long int l = lcm(a, b);
  cout << g << '\n' << l << '\n';
  return 0;
}
