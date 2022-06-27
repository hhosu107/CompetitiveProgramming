#include<bits/stdc++.h>
using namespace std;

int main () {
  int G;
  cin >> G;
  map<int, int> factors;
  for(int i=1; i*i<G; i++) {
    if (G % i == 0) {
      factors[i] = G / i;
    }
  }
  vector<int> weights;
  for(auto it=factors.begin(); it!=factors.end(); it++) {
    if ((it->first + it->second) % 2 == 0) {
      weights.push_back((it->first + it->second) / 2);
    }
  }
  if (weights.size() == 0)
    cout << -1 << endl;
  else {
    sort(weights.begin(), weights.end());
    for(int w: weights)
      cout << w << endl;
  }
  return 0;
}
