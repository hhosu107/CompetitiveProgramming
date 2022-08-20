#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Sol) At least 8 required.
// 8~12: able.
// 13: 5 + 3 + 3 + 2.
// ...
// In general, multiple of 4 can be solved with 2 * multiple of 2.
// multiple of 2 not 4 can be solved with 2 * (multiple of 2 + 1).
// What about odds?
// 1) 4k + 1: use 2, 3
// 2) 4k + 3: use 2, 5.
vector<int> primes;
unordered_set<int> primes_set;

pair<int, int> solve(int n) {
  for(int p: primes) {
    if (primes_set.find(n - p) != primes_set.end()) {
      return make_pair(p, n - p);
    }
  }
  return make_pair(-1, -1);
}

int main () {
  int n;
  cin >> n;
  if (n < 8) {
    cout << -1 << endl;
    return 0;
  }
  primes = vector<int>();
  primes.push_back(2);
  primes.push_back(3);
  primes_set.insert(2);
  primes_set.insert(3);
  for(int i=5; i<=n; i++) {
    bool is_prime = true;
    for(int j=0; j<primes.size() && primes[j] * primes[j] <= i; j++) {
      if(i % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if(is_prime) {
      primes.push_back(i);
      primes_set.insert(i);
    }
  }
  int rem = n % 4;
  pair<int, int> sol, sol_small, sol_large;
  switch(rem) {
    case 0:
      sol = solve(n / 2);
      cout << sol.first << " " << sol.second << " " << sol.first << " " << sol.second << endl;
      break;
    case 1:
      cout << "2 3 ";
      sol = solve(n - 5);
      cout << sol.first << " " << sol.second << endl;
      break;
    case 2:
      sol_small = solve(n / 2 - 1);
      sol_large = solve(n / 2 + 1);
      cout << sol_small.first << " " << sol_small.second << " " << sol_large.first << " " << sol_large.second << endl;
      break;
    case 3:
      cout << "2 5 ";
      sol = solve(n - 7);
      cout << sol.first << " " << sol.second << endl;
      break;
    default:
      cout << -1 << endl;
  }
  return 0;
}
