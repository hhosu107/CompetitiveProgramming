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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return vector<TreeNode*>();
        }
        // Construction of n nodes from n-2 nodes:
        // 1) Select every possible leaf node and add 2 nodes on them.
        // 2) For 2n + 1-sized tree, construct by 1 + (1 + (2n-1)) ... 1 + (2n-1, 1)
        // 1 + (1 + 3), 1 + (3 + 1)
        // 1 + (1 + 5), 1 + (3 + 3), 1 + (5 + 1)
        // the number of trees is known as Catalan number.
        vector<vector<TreeNode*>> fbt_per_nodes(10, vector<TreeNode*>());
        TreeNode *initial_node = new TreeNode();
        fbt_per_nodes[0].push_back(initial_node);
        for(int i=1; 2*i+1<=n; i++) {
            // Select each kth, i-1-kth fbt.
            for(int k=0; k<i; k++) {
                for (TreeNode *kth_head: fbt_per_nodes[k]) {
                    for (TreeNode *rev_kth_head: fbt_per_nodes[i - 1 - k]) {
                        TreeNode *new_node = new TreeNode(0, kth_head, rev_kth_head);
                        fbt_per_nodes[i].push_back(new_node);
                    }
                }
            }
        }
        return fbt_per_nodes[(n - 1) / 2];
    }
};
