#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll sum(vector<int> &a) {
  ll s = 0;
  for_each(a.begin(), a.end(), [&](int x) {s += x;});
  return s;
}
