class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    int odd_idx = 1;
    int even_idx = 0;
    while (odd_idx < nums.size() && even_idx < nums.size()) {
      if (nums[odd_idx] % 2 == 0 && nums[even_idx] % 2 == 1) {
        swap(nums[odd_idx], nums[even_idx]);
      } else if (nums[odd_idx] % 2 == 1 && nums[even_idx] % 2 == 1) {
        odd_idx += 2;
      } else if (nums[odd_idx] % 2 == 0 && nums[even_idx] % 2 == 0) {
        even_idx += 2;
      } else {
        odd_idx += 2;
        even_idx += 2;
      }
    }
    return nums;
  }
};
