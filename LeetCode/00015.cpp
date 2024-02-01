#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct triplet {
  vector<int> x = vector<int>(0, 3);

  triplet(vector<int> y = vector<int>(3, 0)) : x(y) {}

  void operator=(const triplet &a) {
    x[0] = a.x[0];
    x[1] = a.x[1];
    x[2] = a.x[2];
  }

  bool operator<(const triplet &a) const {
    if (x[0] == a.x[0] && x[1] == a.x[1]) {
      return x[2] < a.x[2];
    } else if (x[0] == a.x[0]) {
      return x[1] < a.x[1];
    }
    return x[0] < a.x[0];
  }

  bool operator==(const triplet &a) const {
    return (x[0] == a.x[0] && x[1] == a.x[1] && x[2] == a.x[2]);
  }
};

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    priority_queue<triplet> sol = priority_queue<triplet>();
    for (int i = 0; i < size - 1; i++) {
      int a = nums[i];
      int start = i + 1;
      int end = size - 1;
      while (start < end) {
        int b = nums[start];
        int c = nums[end];
        if (a + b + c == 0) {
          vector<int> vect{a, b, c};
          triplet trip(vect);
          if (sol.empty()) {
            sol.push(trip);
          } else {
            triplet top = sol.top();
            if (!(top == trip)) {
              sol.push(trip);
            }
          }
          end--;
          start++;
        } else if (a + b + c > 0) {
          end--;
        } else {
          start++;
        }
      }
    }
    vector<vector<int>> ret = vector<vector<int>>(0, vector<int>(0));
    while (!sol.empty()) {
      triplet top = sol.top();
      vector<int> res{top.x[0], top.x[1], top.x[2]};
      ret.push_back(res);
    }
    return ret;
  }
};

int main() {
  vector<int> n = vector<int>();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int tmp;
    cin >> tmp;
    n.push_back(tmp);
  }
  Solution x = Solution();
  vector<vector<int>> y = x.threeSum(n);
  for (vector<int> xx : y) {
    for (int xxx : xx) {
      cout << xxx << ' ';
    }
    cout << endl;
  }
  return 0;
}
