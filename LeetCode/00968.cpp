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
  map<TreeNode *, bool> covered; // Initialized with false
  set<TreeNode *> used;

  void treeCover(TreeNode *parent, TreeNode *curr) {
    if (curr == nullptr)
      return;
    if (curr->left == nullptr && curr->right == nullptr) {
      if (parent == nullptr) {
        covered[curr] = true;
        used.insert(curr);
      }
      return;
    }
    treeCover(curr, curr->left);
    treeCover(curr, curr->right);
    if ((!covered[curr] && parent == nullptr) ||
        (curr->left != nullptr && !covered[curr->left]) ||
        (curr->right != nullptr && !covered[curr->right])) {
      used.insert(curr);
      if (curr->left != nullptr) {
        covered[curr->left] = true;
      }
      if (curr->right != nullptr) {
        covered[curr->right] = true;
      }
      if (parent != nullptr) {
        covered[parent] = true;
      }
      covered[curr] = true;
    }
  }

  int minCameraCover(TreeNode *root) {
    used = set<TreeNode *>();
    treeCover(nullptr, root);
    return used.size();
  }
};

// Fuck...
// Tree DP equation:
/*
 * ret = 1 + getMinCamera(root->left, 1) + getMinCamera(root->right, 1);

parentHasCamera : 1
-> ret = min(ret, getMinCamera(root->left, 0) + getMinCamera(root->right, 0));

parentHasCamera : 0
-> ret = min(ret, 1 + getMinCamera(root->left->left, 1) +
getMin(root->left->right, 1) + getMin(root->right, 0);
-> ret = min(ret, 1 + getMinCamera(root->right->left, 1) +
getMin(root->right->right, 1) + getMin(root->left, 0);
*/
/* 대신 이 다음 greedy로 풀도록 유도했을 것 (어느 곳에 umbrella 씌워야 하는지?)
