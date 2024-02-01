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
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    q.push(root);
    while (!q.empty()) {
      TreeNode *q1 = q.front();
      q.pop();
      TreeNode *q2 = q.front();
      q.pop();
      if (q1 == nullptr && q2 == nullptr)
        continue;
      if (q1 == nullptr || q2 == nullptr)
        return false;
      if (q1->val != q2->val)
        return false;
      q.push(q1->left);
      q.push(q2->right);
      q.push(q1->right);
      q.push(q2->left);
    }
    return true;
  }
};
