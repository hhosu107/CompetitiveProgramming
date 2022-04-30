#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
using namespace std;


using ll = long long;
/*
We have (sum(x_i))^2 and sum(x_i^2). they might differ.
Add up to k elements (y_1, ..., y_m) to make
(sum(x_i) + sum(y_j))^2 == sum(x_i^2) + sum(y_j^2).
sol) sum(x_i)^2 + sum(y_j)^2 + 2*sum(x_i)*sum(y_j)
==
sum(x_i^2) + sum(y_j^2).

We know sum(x_i^2) - sum(x_i)^2, so we have to adjust y_j's
so that (sum(y_j) - 2*sum(x_i))*sum(y_j) - sum(y_j^2) = sum(x_i^2) - sum(x_i)^2 (constant)
2*(sum(y_i * y_j) - sum(x_i)sum(y_j)) = sum(x_i^2) - sum(x_i)^2.
Here the right side = 2 * sum(y_k * y_l). Can we derive more?
Small: (a + k)^2 = b + k^2. We can solve this in time.
(a^2 + 2ak -b) = 0; 2ak = (-a^2 + b). => k = (-a^2 + b) / (2a).
*/
int main(){
  int T;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T;
  for(int t=1; t<=T; t++) {
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    ll sum_x = 0;
    ll sum_x2 = 0;
    for(auto &e: x) {
      cin >> e;
      sum_x += e;
      sum_x2 += e * e;
    }
    cout << "Case #" << t << ": ";
    ll right_side = (-(sum_x * sum_x) + sum_x2);
    if (right_side == 0) {
      cout << "0\n";
      continue;
    }
    if (sum_x == 0) {
      cout << "IMPOSSIBLE\n";
      continue;
    } else {
      if (right_side % (2 * sum_x) != 0) {
        cout << "IMPOSSIBLE\n";
        continue;
      }
      cout << (right_side / (2 * sum_x)) << '\n';
    }
  }
  return 0;
}
