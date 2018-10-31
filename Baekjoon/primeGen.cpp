#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> primes;
int main(){
  int N;
  ios::sync_with_stdio(false);
  cin >> N;
  primes = vector<int>();
  primes.push_back(2);
  for(int i=3; i<N; i+=2){
    bool flag = false;
    for(int j=0; j<primes.size() && primes[j] * primes[j] < i && flag == false; j++){
      if(i % primes[j] == 0) flag = true;
    }
    if(!flag) primes.push_back(i);
  }
  for(int p : primes)
    cout << p << ' ';
  cout << '\n';
  return 0;
}
