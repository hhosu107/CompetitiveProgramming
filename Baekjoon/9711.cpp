#include<iostream>
#include<array>
#include<vector>
using namespace std;

using ll = long long;
ll denom = 1000000007;

vector<ll> matrix_fib(ll n) {
  vector<ll> result(4, 0);
  if (n == 0) {
    result[0] = result[3] = (1 % denom);
    result[1] = result[2] = 0;
    return result;
  }
  if (n == 1) {
    result[0] = result[1] = result[2] = (1 % denom);
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
  int T;
  ll n, m;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  for(int i=1; i<=T; i++) {
    cin >> n >> m;
    denom = m;
    vector<ll> result = matrix_fib(n);
    cout << "Case #" << i << ": " << result[1] << '\n';
  }
  return 0;
}
