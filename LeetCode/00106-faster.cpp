i /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
   *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
   * right(right) {}
   * };
   */
    class Solution {

  void CreateMapping(unordered_map<int, int> &m, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++) {
      m[inorder[i]] = i;
    }
  }

  TreeNode *Solve(vector<int> &postorder, vector<int> &inorder,
                  unordered_map<int, int> &m, int start, int end, int &index) {
    if (start > end || index < 0)
      return NULL;

    TreeNode *root = new TreeNode(postorder[index]);

    int pos = m[postorder[index--]];

    root->right = Solve(postorder, inorder, m, pos + 1, end, index);
    root->left = Solve(postorder, inorder, m, start, pos - 1, index);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int index = postorder.size() - 1;
    int start = 0;
    int end = index;

    unordered_map<int, int> m;

    CreateMapping(m, inorder);

    return Solve(postorder, inorder, m, start, end, index);
  }
};
