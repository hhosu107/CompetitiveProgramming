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
    int left_height(TreeNode* node)
    {
        int ht = 0;
        while (node) {
            ht++;
            node = node->left;
        }
        // Return the left height obtained
        return ht;
    }
 
    int right_height(TreeNode* node)
    {
        int ht = 0;
        while (node) {
            ht++;
            node = node->right;
        }
        // Return the right height obtained
        return ht;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int lh = left_height(root);
        int rh = right_height(root);
        if (lh == rh) {
            // Full tree. We know the number of nodes.
            return (1 << lh) - 1;
        }
        // Not full. Track each left/right is full tree or not.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
