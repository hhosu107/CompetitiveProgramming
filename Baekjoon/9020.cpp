#include<iostream>
#include<vector>
int primes[2500];
bool isprime[10001];

using namespace std;
int main(){
  int T;
  int N;
  primes[0] = 2;
  isprime[2] = true;
  int cnt_primes = 1;
  for(int i=3; i<10000; i++){
    bool flag = true;
    for(int j=0; j<cnt_primes && primes[j] * primes[j] <= i; j++){
      if (i % primes[j] == 0) { flag = false; break; }
    }
    if (flag) {primes[cnt_primes++] = i; isprime[i] = true;}
  }
  cin >> T;
  for(int t=0; t<T; t++){
    int n;
    cin >> n;
    int left = -1, right = 10001;
    for(int i=0; i<cnt_primes && primes[i] <= (n / 2); i++){
      if (isprime[n - primes[i]]){
        left = primes[i];
        right = n - primes[i];
      }
    }
    cout << left << " " << right << endl;
  }
  return 0;
}
