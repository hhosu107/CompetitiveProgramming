#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meeting {
  int start, people;
  meeting() : start(0), people(0) {}
  meeting(int s, int p) : start(s), people(p) {}
  bool operator<(const meeting& m) const {
    return start < m.start;
  }
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<meeting> peoples(n, meeting());
  int dummyl, dummyr;
  for(int i=0; i<n; i++) {
    cin >> peoples[i].start >> dummyr >> peoples[i].people;
  }
  sort(peoples.begin(), peoples.end());
  vector<int> dp(n);
  dp[0] = peoples[0].people;
  int m = dp[0];
  for(int i=1; i<n; i++) {
    if (i == 1) {
      dp[i] = peoples[i].people;
      m = max(m, dp[i]);
    }
    else if (i == 2) {
      dp[i] = max(dp[i-1], peoples[i].people + peoples[i-2].people);
      m = max(m, dp[i]);
    }
    else {
      dp[i] = max(max(dp[i-1], peoples[i].people + dp[i-2]), peoples[i].people + dp[i-3]);
      m = max(m, dp[i]);
    }
  }
  cout << m << '\n';
}
