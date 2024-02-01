class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int curr_num = nums[0];
    int curr_uniq_idx = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != curr_num) {
        curr_num = nums[i];
        nums[curr_uniq_idx] = nums[i];
        curr_uniq_idx++;
      }
    }
    return curr_uniq_idx;
  }
};
