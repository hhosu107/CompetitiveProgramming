#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main () {
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &i: a) cin >> i;
  sort(a.begin(), a.end());
  ll sum_sum = 0;
  ll waited_time = 0;
  for(auto i: a) {
    waited_time += i;
    sum_sum += waited_time;
  }
  cout << sum_sum << endl;
  return 0;
}
