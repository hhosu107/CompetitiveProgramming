#include<iostream>
#include<array>
using namespace std;

array<int, 1001> fib;

int main () {
  int n;
  cin >> n;
  fib[0] = fib[1] = 1;
  fib[2] = 3;
  for(int i=3; i<=n; i++)
    fib[i] = (fib[i-1] + 2 * fib[i-2]) % 10007;
  cout << fib[n] << endl;
  return 0;
}
