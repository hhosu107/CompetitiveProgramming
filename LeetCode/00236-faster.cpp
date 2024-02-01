/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool findPath(TreeNode *root, vector<TreeNode *> &path, TreeNode *k) {
    // base case
    if (root == nullptr)
      return false;

    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root);

    // See if the k is same as root's key
    if (root == k)
      return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
      return true;

    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> p_path, q_path;
    bool p_find = findPath(root, p_path, p);
    bool q_find = findPath(root, q_path, q);
    int i;
    for (i = 0; i < p_path.size() && i < q_path.size(); i++) {
      if (p_path[i] != q_path[i])
        break;
    }
    return p_path[i - 1];
  }
};
