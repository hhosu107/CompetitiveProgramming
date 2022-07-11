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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> found_vals;
        return findTargetRec(root, k, found_vals);
    }
    bool findTargetRec(TreeNode* root, int k, unordered_set<int> &found_vals) {
        if (root == nullptr)
            return false;
        if (found_vals.find(k - root->val) != found_vals.end()) {
            return true;
        }
        found_vals.insert(root->val);
        return findTargetRec(root->left, k, found_vals) || findTargetRec(root->right, k, found_vals);
    }
};
