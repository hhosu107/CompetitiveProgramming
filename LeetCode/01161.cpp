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
  int maxLevelSum(TreeNode *root) {
    // Sol) Use queue to access.
    queue<pair<TreeNode *, int>> node_heights;
    node_heights.push({root, 1});
    map<int, int> level_value;
    while (!node_heights.empty()) {
      auto [node, height] = node_heights.front();
      node_heights.pop();
      level_value[height] += node->val;
      if (node->left != nullptr) {
        node_heights.push({node->left, height + 1});
      }
      if (node->right != nullptr) {
        node_heights.push({node->right, height + 1});
      }
    }
    int max_value = -2000000000;
    int max_level = -1;
    for (auto it = level_value.begin(); it != level_value.end(); it++) {
      if (max_value < it->second) {
        max_level = it->first;
        max_value = it->second;
      }
    }
    return max_level;
  }
};
