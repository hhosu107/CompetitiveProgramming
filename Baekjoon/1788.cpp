#include<iostream>
#include<array>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

using ll = long long;
ll denom = 1000000000;

vector<ll> matrix_fib(ll n) {
  vector<ll> result(4, 0);
  if (n == 0) {
    result[0] = result[3] = 1;
    result[1] = result[2] = 0;
    return result;
  }
  if (n == 1) {
    result[0] = result[1] = result[2] = 1;
    result[3] = 0;
    return result;
  }
  vector<ll> prev = matrix_fib(n/2);
  result[0] = (prev[0] * prev[0] + prev[1] * prev[2]) % denom;
  result[1] = (prev[0] * prev[1] + prev[1] * prev[3]) % denom;
  result[2] = (prev[2] * prev[0] + prev[3] * prev[2]) % denom;
  result[3] = (prev[2] * prev[1] + prev[3] * prev[3]) % denom;
  if (n % 2 == 1) {
    vector<ll> pad(4, 0);
    pad[0] = (result[0] + result[1]) % denom;
    pad[1] = (result[0]) % denom;
    pad[2] = (result[2] + result[3]) % denom;
    pad[3] = (result[2]) % denom;
    return pad;
  }
  return result;
}

int main () {
  ll n;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  vector<ll> result = matrix_fib(abs(n));
  cout << ((n < 0 && n % 2 == 0) ? -1 : (n == 0 ? 0 : 1)) << endl;
  cout << result[1] << endl;
  return 0;
}
