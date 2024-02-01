class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int length = nums.size();
    int nondup_index = 0;
    int index = 1;
    if (length == 0)
      return 0;
    int curr_val = nums[0];
    while (index < length) {
      if (curr_val == nums[index]) {
        index++;
      } else {
        nums[nondup_index] = curr_val;
        curr_val = nums[index];
        index++;
        nondup_index++;
      }
    }
    nums[nondup_index] = curr_val;
    nondup_index++;
    return nondup_index;
  }
};
