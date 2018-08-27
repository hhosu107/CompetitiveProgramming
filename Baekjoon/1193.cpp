#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  int n=1;
  while(n * (n + 1) / 2 < X) n++;
  if(n % 2 != 0) printf("%d/%d\n", n*(n+1)/2 + 1 - X, X - (n-1)*n/2);
  else printf("%d/%d\n", X - (n-1)*n/2, n*(n+1)/2 + 1 - X);
  return 0;
}
