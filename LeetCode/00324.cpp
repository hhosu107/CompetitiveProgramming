/*class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i < nums.size() - i - (nums.size() % 2 ? 0 : 1); i += 2) {
            swap(nums[i], nums[nums.size() - i - (nums.size() % 2 ? 0 : 1)]);
        }
    }
};*/
// Can this be O(n)?
class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    for (int i = 0; i + 1 < nums.size(); ++i) {
      if ((i % 2) == (nums[i] < nums[i + 1])) {
        swap(nums[i], nums[i + 1]);
      }
    }
  }
  /* proof
     * Do with induction.
     * 1. nums.size() == 1 True.
     * 2. nums.size() == 2 : swap only if nums[0] >= nums[1].
     * 3. Suppose it holds on nums.size() == 2 * n.
     * 4. Let it be increased by 1. We compare nums[2 * n - 1] and nums[2 * n].
     *    If nums[2 * n - 1] > nums[2 * n], we don't have to swap.
     *    Else we swap. Before swap, nums[2 * n - 2] <= nums[2 * n - 1] holds,
     *    and since nums[2 * n] >= nums[2 * n - 1], swapping doesn't harm the
     *    wiggle condition at the previous index.
     * 3. Suppose it holds on nums.size() == 2 * n + 1.
     * 4. Let it be increased by 1. We compare nums[2 * n] and nums[2 * n + 1].
     *    If nums[2 * n] <= nums[2 * n + 1], we dony' have to swap.
     *    Else we swap. Before swap, nums[2 * n - 1] > nums[2 * n] holds, and
     *    since nums[2 * n + 1] < nums[2 * n], swapping doesn't harm the wiggle
     *    condition at the previous index.
     * Thus this one-path induction generates the full wiggle condition.
};
