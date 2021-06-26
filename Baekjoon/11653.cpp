#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int primes[800000];
int main(){
  int N;
  primes[0] = 2;
  int cnt_primes = 1;
  for(int i=3; i<10000000; i+=2){
    bool flag = true;
    for(int j=0; j<cnt_primes && primes[j] * primes[j] <= i; j++){
      if (i % primes[j] == 0) { flag = false; break; }
    }
    if (flag) { primes[cnt_primes++] = i; }
  }
  cin >> N;
  int p_search = 0;
  while(N > 1){
    while(N % primes[p_search] == 0){
      cout << primes[p_search] << endl;
      N /= primes[p_search];
    }
    p_search++;
  }
  return 0;
}
