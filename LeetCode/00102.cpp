<Del>/**
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_order = vector<vector<int>>();
        if (root == nullptr) return level_order;
        queue<pair<TreeNode*, int>> level_nodes;
        level_nodes.push({root, 0});
        while(!level_nodes.empty()) {
            pair<TreeNode*, int> head = level_nodes.front();
            level_nodes.pop();
            if (level_order.size() == head.second) level_order.push_back(vector<int>());
            level_order[head.second].push_back(head.first->val);
            if (head.first->left != nullptr) level_nodes.push({head.first->left, head.second + 1});
            if (head.first->right != nullptr) level_nodes.push({head.first->right, head.second + 1});
        }
        return level_order;
    }
};
