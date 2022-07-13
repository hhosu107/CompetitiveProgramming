i/**
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
    bool isSame(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr)) return false;
        if (left->val != right->val) return false;
        bool lr_mirror = isSame(left->left, right->right);
        bool rl_mirror = isSame(left->right, right->left);
        return (lr_mirror && rl_mirror);
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};
