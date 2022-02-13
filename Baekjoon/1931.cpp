#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using pii = pair<int, int>;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int s, e;
  vector<pii> v = vector<pii>(n);
  for (auto &i : v)
    cin >> i.second >> i.first;
  sort(v.begin(), v.end());
  int noncollide_count = 0;
  int curr_e = -1;
  for(auto i : v) {
    if (i.second >= curr_e) {
      curr_e = i.first;
      noncollide_count++;
    }
  }
  cout << noncollide_count << endl;
  return 0;
}
