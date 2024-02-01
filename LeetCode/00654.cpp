/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int maxIndex(vector<int> &nums, int l, int r) {
    if (l == r)
      return l;
    int max_num = nums[l];
    int max_index = l;
    for (int i = l + 1; i <= r; i++) {
      if (max_num < nums[i]) {
        max_num = nums[i];
        max_index = i;
      }
    }
    return max_index;
  }
  TreeNode *recursiveMaxBinTree(vector<int> &nums, int l, int r) {
    if (l > r)
      return nullptr;
    if (l == r)
      return new TreeNode(nums[l]);
    int max_index = maxIndex(nums, l, r);
    TreeNode *left_child = recursiveMaxBinTree(nums, l, max_index - 1);
    TreeNode *right_child = recursiveMaxBinTree(nums, max_index + 1, r);
    return new TreeNode(nums[max_index], left_child, right_child);
  }
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return recursiveMaxBinTree(nums, 0, nums.size() - 1);
  }
};
