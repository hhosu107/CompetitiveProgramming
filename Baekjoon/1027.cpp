#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main () {
  int n;
  cin >> n;
  vector<int> builds(n);
  for(auto &b: builds) cin >> b;
  // multiset<int> left_view, right_view;
  vector<int> left_count(n), right_count(n);
  for(int i=0; i<n; i++) {
    for(int j=i-1; j>=0; j--) {
      if (builds[j] >= builds[i]) {
        left_count[i] = i - j - 1;
        break;
      }
      if (left_count[i] == 0) left_count[i] = i;
    }
    for(int j=i+1; j<n; j++) {
      if (builds[j] >= builds[i]) {
        right_count[i] = j - i - 1;
        break;
      }
      if (right_count[i] == 0) right_count[i] = n - i - 1;
    }
  }
  int max_count = 0;
  for(int i=0; i<n; i++) {
    max_count = max(max_count, left_count[i] + right_count[i]);
  }
  cout << max_count << endl;
  return 0;
}
