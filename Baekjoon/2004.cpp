// 2004: count ending 0's from binom(n, m)
// idea: count 5's/2's on the fraction and calculate difference.
// sum: [n/2] + [n/2^2] + ...
#include<iostream>
using namespace std;
long long int n, m;
long long int u2, u5, d21, d51, d22, d52;
long long int countexp(long long int base, long long int lim){
  long long int b = base;
  long long int count = 0;
  for(;b<=lim; b*=base)
    count += lim/b;
  return count;
}
int main(){
  cin >> n >> m;
  u2 = countexp(2, n);
  u5 = countexp(5, n);
  d21 = countexp(2, m);
  d51 = countexp(5, m);
  d22 = countexp(2, n-m);
  d52 = countexp(5, n-m);
  cout << (u2 - d21 - d22 < u5 - d51 - d52 ? u2 - d21 - d22 : u5 - d51 - d52) << endl;
  return 0;
}
