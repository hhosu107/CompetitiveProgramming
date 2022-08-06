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
    void getSortedOrder(TreeNode* root, vector<int>& ascend) {
        if (root == nullptr) return;
        getSortedOrder(root->left, ascend);
        ascend.emplace_back(root->val);
        getSortedOrder(root->right, ascend);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // Sol) get two vector<int> from them, and merge.
        vector<int> arr1;
        vector<int> arr2;
        getSortedOrder(root1, arr1);
        getSortedOrder(root2, arr2);
        vector<int> merged;
        int arr1_idx = 0, arr1_len = arr1.size(), arr2_idx = 0, arr2_len = arr2.size();
        while(arr1_idx < arr1_len || arr2_idx < arr2_len) {
            if (arr1_idx == arr1_len) {
                merged.push_back(arr2[arr2_idx]);
                arr2_idx++;
            } else if (arr2_idx == arr2_len) {
                merged.push_back(arr1[arr1_idx]);
                arr1_idx++;
            } else {
                if (arr1[arr1_idx] <= arr2[arr2_idx]) {
                    merged.push_back(arr1[arr1_idx]);
                    arr1_idx++;
                } else {
                    merged.push_back(arr2[arr2_idx]);
                    arr2_idx++;
                }
            }
        }
        return merged;
    }
};
