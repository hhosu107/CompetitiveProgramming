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
  unordered_map<TreeNode *, int>
      tree_sum; // These maps just make the whole code slowest as possible.
                // If we just return the subsum and indicator of BST-or-not as
                // the return value, we don't have to save them.
  unordered_map<TreeNode *, bool> is_bst;
  bool exists_positive_element = false;
  int max_element = -50000;
  int max_bst_sum = 0;

  pair<int, int> check_bst_calculate_sum_and_return_min_max(TreeNode *root) {
    if (root->left == nullptr && root->right == nullptr) {
      is_bst[root] = true;
      tree_sum[root] = root->val;
      if (root->val > 0) {
        exists_positive_element = true;
      }
      max_bst_sum = max(max_bst_sum, root->val);
      max_element = max(max_element, root->val);
      return make_pair(root->val, root->val);
    } else if (root->right == nullptr) { // left bst + root > left's max key
      pair<int, int> left_minmax =
          check_bst_calculate_sum_and_return_min_max(root->left);
      tree_sum[root] = tree_sum[root->left] + root->val;
      if (!is_bst[root->left] || left_minmax.second >= root->val) {
        is_bst[root] = false;
      } else {
        is_bst[root] = true;
        max_bst_sum = max(max_bst_sum, tree_sum[root]);
      }
      if (root->val > 0) {
        exists_positive_element = true;
      }
      max_element = max(max_element, root->val);
      return make_pair(min(left_minmax.first, root->val),
                       max(left_minmax.second, root->val));
    } else if (root->left == nullptr) { // right bst + root < right's min key
      pair<int, int> right_minmax =
          check_bst_calculate_sum_and_return_min_max(root->right);
      tree_sum[root] = tree_sum[root->right] + root->val;
      if (!is_bst[root->right] || right_minmax.first <= root->val) {
        is_bst[root] = false;
      } else {
        is_bst[root] = true;
        max_bst_sum = max(max_bst_sum, tree_sum[root]);
      }
      if (root->val > 0) {
        exists_positive_element = true;
      }
      max_element = max(max_element, root->val);
      return make_pair(min(right_minmax.first, root->val),
                       max(right_minmax.second, root->val));
    }
    // Take care both: left bst, right bst, left's max < root < right's min
    pair<int, int> left_minmax =
        check_bst_calculate_sum_and_return_min_max(root->left);
    pair<int, int> right_minmax =
        check_bst_calculate_sum_and_return_min_max(root->right);
    tree_sum[root] = tree_sum[root->left] + tree_sum[root->right] + root->val;
    if (!is_bst[root->left] || !is_bst[root->right] ||
        left_minmax.second >= root->val || right_minmax.first <= root->val) {
      is_bst[root] = false;
    } else {
      is_bst[root] = true;
      max_bst_sum = max(max_bst_sum, tree_sum[root]);
    }
    if (root->val > 0) {
      exists_positive_element = true;
    }
    max_element = max(max_element, root->val);
    pair<int, int> ret_minmax =
        make_pair(min({left_minmax.first, root->val, right_minmax.first}),
                  max({left_minmax.second, root->val, right_minmax.second}));
    return ret_minmax;
  }

  int maxSumBST(TreeNode *root) {
    pair<int, int> root_minmax =
        check_bst_calculate_sum_and_return_min_max(root);
    return max_bst_sum;
  }
};
