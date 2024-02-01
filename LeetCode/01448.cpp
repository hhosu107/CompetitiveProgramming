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
  int numGoodNodes(TreeNode *root, int parental_max_val) {
    if (root == nullptr)
      return 0;
    int leftGoodNodes =
        numGoodNodes(root->left, max(parental_max_val, root->val));
    int rightGoodNodes =
        numGoodNodes(root->right, max(parental_max_val, root->val));
    return leftGoodNodes + rightGoodNodes +
           (root->val >= parental_max_val ? 1 : 0);
  }
  int goodNodes(TreeNode *root) {
    // Sol) Give a maximum value to childs.
    return numGoodNodes(root, -10001);
  }
};
