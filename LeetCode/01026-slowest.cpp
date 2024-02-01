class Solution {
public:
  int maxgap = 0;

  set<int> maxAncestorDiffSet(TreeNode *root) {
    if (root == nullptr)
      return set<int>();
    if (root->left == nullptr && root->right == nullptr)
      return set<int>{root->val};
    set<int> leftset = maxAncestorDiffSet(root->left);
    set<int> rightset = maxAncestorDiffSet(root->right);
    for (int l : leftset)
      maxgap = max(maxgap, abs(root->val - l));
    for (int r : rightset)
      maxgap = max(maxgap, abs(root->val - r));
    leftset.insert(rightset.begin(), rightset.end());
    leftset.insert(root->val);
    return leftset;
  }
  int maxAncestorDiff(TreeNode *root) {
    maxAncestorDiffSet(root);
    return maxgap;
  }
};

// Bottom up naive solution:
// compute maximum difference between root and left nodes / root and right
// nodes, and return the set of values in this subtree.
