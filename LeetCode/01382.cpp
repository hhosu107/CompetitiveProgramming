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
    void storeBSTNodes(TreeNode* root, vector<TreeNode*> &nodes) {
        if (root == nullptr) return;
        // store left first, root, and right. It generates the sorted list of nodes.
        storeBSTNodes(root->left, nodes);
        nodes.push_back(root);
        storeBSTNodes(root->right, nodes);
    }
    
    TreeNode* buildBSTWithBinarySearch(vector<TreeNode*> &nodes, int start, int end) {
        if (start > end) return nullptr; // base case
        int mid = (start + end) / 2;
        TreeNode *root = nodes[mid]; // This node will be returned with..
        root->left = buildBSTWithBinarySearch(nodes, start, mid - 1);
        root->right = buildBSTWithBinarySearch(nodes, mid + 1, end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        storeBSTNodes(root, nodes);
        TreeNode* balanced_root = buildBSTWithBinarySearch(nodes, 0, nodes.size() - 1);
        return balanced_root;
    }
};

// 헷갈려서 찾아봤다...
// 기본: BST는 O(n)에 sorted array로 변환할 수 있다는 것에서 아이디어를 얻어야
// 함.
// 그러면 binary search를 통해 balanced binary search tree로 만들 수 있으니까.
// recursive하게, 양 쪽 node 갯수 차이를 1 이하로 만드는 짓을 recurse하면,
// 해당 left/right의 높이 차이가 최대 1이 된다.
