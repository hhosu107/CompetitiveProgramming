#include <vector>
using namespace std;

class Solution {
public:
  int missing(int idx, vector<int> &nums) { return nums[idx] - nums[0] - idx; }
  int missingElement(vector<int> &nums, int k) {
    int n = nums.size();
    // If kth number is larger than the last element of the array
    if (k > missing(n - 1, nums)) {
      return nums[n - 1] + k - missing(n - 1, nums);
    }
    int left = 0, right = n - 1, pivot;
    while (left != right) {
      pivot = left + (right - left) / 2;
      if (missing(pivot, nums) < k)
        left = pivot + 1;
      else
        right = pivot;
    }
    // we find left that is larger than kth missing number where left-1 is
    // smaller than kth missing number.
    return nums[left - 1] + k - missing(left - 1, nums);
  }
};
