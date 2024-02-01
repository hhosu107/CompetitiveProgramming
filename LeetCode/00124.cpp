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
  int ans = 0;
  int maxNum = 0;
  int getAns(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int now = root->val; // Records the case that only the root node used for
                         // the path.
    maxNum = max(maxNum, now); // Records the maximum node.

    int left = getAns(root->left);
    int right = getAns(root->right);

    // sum contains
    int sum = max(now, now + left); // rootval vs path containing root + left
    sum = max(sum, now + right);    // path containing root + left vs path
                                    // containing root + right
    ans =
        max(ans, sum); // ans represents the path from parents to this subtree.
                       // Either left or right can be contained here (sum).
    ans = max(ans, now + right + left); // path containing left + subtree root +
                                        // right (i.e., ignoring parents)
    return max(sum, 0);                 // returns the parental path.
  }

  int maxPathSum(TreeNode *root) {
    ans = root->val;
    maxNum = root->val;
    getAns(root);
    return maxNum >= 0 ? ans
                       : maxNum; // if maxNum < 0, the maximum path is just the
                                 // single node containing maxNum.
  }
};
