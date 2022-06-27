/*
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
    int countNodesWithRoot(TreeNode* root) {
        if (root == nullptr) return 0;
        else return 1 + countNodesWithRoot(root->left) + countNodesWithRoot(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (root->val == x) {
            int leftCount = countNodesWithRoot(root->left);
            int rightCount = countNodesWithRoot(root->right);
            int maxCount = max(leftCount, rightCount);
            if (2 * maxCount > n) return true;
            else return false;
        } else {
            queue<pair<TreeNode*, TreeNode*>> node_checker;
            node_checker.push({nullptr, root});
            while(!node_checker.empty()) {
                pair<TreeNode*, TreeNode*> curr = node_checker.front();
                node_checker.pop();
                if ((curr.second)->val == x) {
                    int nodesUnderValue = countNodesWithRoot(curr.second);
                    if (2 * nodesUnderValue < n) return true;
                    nodesUnderValue = countNodesWithRoot((curr.second)->left);
                    if (2 * nodesUnderValue > n) return true;
                    nodesUnderValue = countNodesWithRoot((curr.second)->right);
                    if (2 * nodesUnderValue > n) return true;
                    return false;
                }
                if ((curr.second)->left != nullptr) {
                    node_checker.push({curr.second, (curr.second)->left});
                }
                if ((curr.second)->right != nullptr) {
                    node_checker.push({curr.second, (curr.second)->right});
                }
            }
        }
        return false;
        // Sol) Divide into cases
        // If x == root's value? -> check left/right child's count. If left is more, choose left / vice versa. Finally, check whether or not the count exceeds.
        // If x == one of the childs? -> take the direct parent. And count number of the nodes that under x.
    }
};*
