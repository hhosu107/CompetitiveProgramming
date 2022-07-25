#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> nums(n), unique_nums(n);
  set<int> ordered;
  for(int i=0 ;i<n; i++) {
    cin >> nums[i];
    unique_nums[i] = nums[i];
  }
  sort(unique_nums.begin(), unique_nums.end());
  unique_nums.erase(unique(unique_nums.begin(), unique_nums.end()), unique_nums.end());
  for(int i=0; i<n; i++) {
    cout << lower_bound(unique_nums.begin(), unique_nums.end(), nums[i]) - unique_nums.begin() << " ";
  }
  cout << '\n';
  return 0;
}
