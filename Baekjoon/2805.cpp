#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long int height;
  int n;
  long long int m;
  cin >> n >> m;
  vector<long long int> trees = vector<long long int>(n + 1);
  for (auto &x: trees) {
    cin >> x;
  }
  trees[n] = 0;
  sort(trees.begin(), trees.end());
  long long int min = trees[0], max = trees[n];
  long long int ans = -1;
  while(min + 1 < max){
    long long int cen = (min + max) / 2;
    long long int parts = 0;
    for(auto x : trees) {
      parts += (x < cen ? 0 : x - cen);
    }
    if (parts == m) {
      ans = cen;
      break;
    }
    if (parts > m){
      min = cen;
    } else {
      max = cen - 1;
    }
  }
  if (ans != -1) {}
  else {
    long long int trial = max;
    long long int trialdown = min;
    long long int partsup = 0;
    long long int partsdown = 0;
    for(auto x : trees) {
      partsup += (x < trial ? 0 : x - trial);
      partsdown += (x < trialdown ? 0 : x - trialdown);
    }
    if (partsup >= m) ans = max;
    else if (partsdown >= m) ans = min;
    else ans = min - 1;
  }
  cout << ans << '\n';
  return 0;
}
