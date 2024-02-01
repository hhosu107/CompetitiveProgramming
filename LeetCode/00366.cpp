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
  vector<vector<int>> solution;
  int getHeight(
      TreeNode *root) { // leafs have 0 as height, others have its maximal
                        // height as maximal depth of its height.
    if (!root)
      return -1;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int currHeight = max(leftHeight, rightHeight) + 1;
    if (this->solution.size() == currHeight) {
      this->solution.push_back({});
    }
    this->solution[currHeight].push_back(root->val);
    return currHeight;
  }
  vector<vector<int>> findLeaves(TreeNode *root) {
    this->solution.clear();
    getHeight(root);
    return this->solution;
  }
};
