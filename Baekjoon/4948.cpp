#include<iostream>

int primes[50000];

using namespace std;

int main(){
  primes[0] = 2;
  int cnt_primes = 1;
  for(int i=3; i<246912; i+=2){
    bool flag = true;
    for(int j=0; j<cnt_primes && primes[j] * primes[j] <= i; j++){
      if (i % primes[j] == 0) { flag = false; break;}
    }
    if (flag) { primes[cnt_primes++] = i; }
  }
  while(1){
    int N;
    cin >> N;
    if (N == 0) break;
    int left = N + 1;
    int right = 2 * N;
    int ans = 0;
    for(int i=0; primes[i] <= right; i++){
      if (primes[i] >= left) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
