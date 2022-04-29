#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> primes;
int main () {
  primes = vector<int>(400000, 4000001);
  primes[0] = 2;
  primes[1] = 3;
  int prime_count = 2;
  for(int i=5; i<4000000; i+=2) {
    bool is_prime = true;
    for(int j=0; j<prime_count && primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      primes[prime_count++] = i;
    }
  }
  int target;
  cin >> target;
  int partial_sum = 0;
  if (target == 1) {
    cout << "0\n";
    return 0;
  }
  int lp = 0, rp = 0;
  int partial_sum_cnt = 0;
  while(primes[rp] <= target) {
    while(partial_sum < target) {
      partial_sum += primes[rp];
      rp++;
    }
    while(partial_sum > target) {
      partial_sum -= primes[lp];
      lp++;
    }
    if (partial_sum == target) {
      partial_sum_cnt++;
      partial_sum -= primes[lp];
      lp++;
    }
  }
  cout << partial_sum_cnt << '\n';
  return 0;
}

