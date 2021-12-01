#include<iostream>
#include<vector>
using namespace std;

int primes[100000];
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> m >> n;
  primes[0] = 2;
  primes[1] = 3;
  if (m <= 2 && n >= 2) cout << 2 << '\n';
  int pcnt = 1;
  for(int i=3; i<=n; i+=2){
    bool flag = true;
    for(int j=0; primes[j] * primes[j] <= i; j++){
      if (i % primes[j] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      primes[pcnt++] = i;
      if (i >= m) cout << i << '\n';
    }
  }
  return 0;
}
