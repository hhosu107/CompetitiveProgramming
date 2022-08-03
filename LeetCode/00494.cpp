#include<iomanip>
#include<vector>
#include<algorithm>
#include<functional>
#include<unordered_map>
using namespace std;

struct MyHash {
    size_t operator()(const pair<int, int>& k) const {
        size_t h1 = hash<int>()(k.first);
        size_t h2 = hash<int>()(k.second);
        return h1 ^ (h2 << 1);
    }
};

class Solution {
  public:
    unordered_map<pair<int, int>, int, MyHash> mem;

    int findTargetSumWays(vector<int>& nums, int target) {
      mem = unordered_map<pair<int, int>, int, MyHash>();
      int index = nums.size() - 1;
      int curr_sum = 0;
      return dp(nums, target, index, curr_sum);
    }
    int dp(vector<int>& nums, int target, int index, int curr_sum) {
      if (mem.find({index, curr_sum}) != mem.end())
        return mem[make_pair(index, curr_sum)];
      if (index < 0 && curr_sum == target)
        return 1;
      if (index < 0)
        return 0;
      int positive = dp(nums, target, index - 1, curr_sum + nums[index]);
      int negative = dp(nums, target, index - 1, curr_sum - nums[index]);
      mem[make_pair(index, curr_sum)] = positive + negative;
      return mem[make_pair(index, curr_sum)];
    }
};

