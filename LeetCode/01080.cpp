/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathMax(TreeNode* root, int limit, int path_sum) {
        if (root->left == nullptr && root->right == nullptr) return path_sum + root->val;
        if (root->left == nullptr) {
            int right_pathmax = pathMax(root->right, limit, path_sum + root->val);
            if (right_pathmax < limit) root->right = nullptr;
            return right_pathmax;
        }
        if (root->right == nullptr) {
            int left_pathmax = pathMax(root->left, limit, path_sum + root->val);
            if (left_pathmax < limit) root->left = nullptr;
            return left_pathmax;
        }
        int left_pathmax = pathMax(root->left, limit, path_sum + root->val);
        int right_pathmax = pathMax(root->right, limit, path_sum + root->val);
        int max_pathmax = max(left_pathmax, right_pathmax);
        if (left_pathmax < limit) root->left = nullptr;
        if (right_pathmax < limit) root->right = nullptr;
        return max_pathmax;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // Sol) For each node, maintain the max path value; if it doesn't, the parent will remove that path.
        int root_pathmax = pathMax(root, limit, 0);
        if (root_pathmax < limit) return nullptr;
        return root;
    }
};
