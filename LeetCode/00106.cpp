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
    TreeNode* binary_construction(vector<int>& inorder, vector<int>& postorder, int inorder_start, int inorder_end, int postorder_start, int postorder_end) {
        if (inorder_start == inorder_end) return nullptr;
        if (inorder_start + 1 == inorder_end) return new TreeNode(inorder[inorder_start]);
        int postorder_root_idx = postorder_end - 1;
        auto it = find(inorder.begin() + inorder_start, inorder.begin() + inorder_end, postorder[postorder_root_idx]);
        int lefttree_size = distance(inorder.begin() + inorder_start, it);
        int righttree_size = inorder_end - inorder_start - 1 - lefttree_size;
        TreeNode* left_child = binary_construction(inorder, postorder, inorder_start, inorder_start + lefttree_size, postorder_start, postorder_start + lefttree_size);
        TreeNode* right_child = binary_construction(inorder, postorder, inorder_start + lefttree_size + 1, inorder_end, postorder_start + lefttree_size, postorder_end - 1);
        TreeNode* subroot = new TreeNode(postorder[postorder_end - 1], left_child, right_child);
        return subroot;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        //TreeNode *root = binary_construction(inorder, postorder, inorder_start, inorder_end, postorder_start, postorder_end);
        TreeNode *root = binary_construction(inorder, postorder, 0, len, 0, len); // [a, b)
        return root;
        // Sol) at the postorder subtree, [left..., right..., subroot] exists.
        // With postorder value, find that value in the inorder array. it selects some pivot.
        // suppose we already have start/end of tree. [a, b] for inorder, [c, d] for postorder. d-1'th index is the root of postorder access.
        // find index e in inorder. then [a, e-1] becomes left child of the tree of inorder search, and then [c, c + (e - a - 1)] becomes left child of the tree of postorder search.
        // vice versa, [e+1, b] becomes right child of the tree of inorder search, and then [c + (e - a), d-1] becomes right child of the tree of postorder search.
    }
};
