// Sol) Top Down construction with preorder execution.
// for each call, maxim contains absolute maximum difference from any ancestor
// to any childs, while mx and mi only contains the path maximum and path
// minimum by this construction.
/*
 * An insight is that:

Given any two nodes on the same root-to-leaf path, they must have the required
ancestor relationship. Therefore, we just need to record the maximum and minimum
values of all root-to-leaf paths and return the maximum difference.

To achieve this, we can record the maximum and minimum values during the
recursion and return the difference when encountering leaves.

Algorithm

Step 1: Define a function helper, which takes three arguments as input and
returns an integer.

The first argument node is the current node, and the second argument cur_max and
third argument cur_min are the maximum and minimum values along the root to the
current node, respectively.

Function helper returns cur_max - cur_min when encountering leaves. Otherwise,
it calls helper on the left and right subtrees and returns their maximum.

Step 2: Run helper on the root and return the result.
*/
class Solution {
public:
  void get(TreeNode *root, int &maxim, int mx, int mi) {
    if (root == NULL) {
      return;
    }
    maxim = max(maxim, max(abs(mx - root->val), abs(mi - root->val)));
    get(root->left, maxim, max(mx, root->val), min(mi, root->val));
    get(root->right, maxim, max(mx, root->val), min(mi, root->val));
    return;
  }
  int maxAncestorDiff(TreeNode *root) {
    int maxim = 0;
    get(root, maxim, root->val, root->val);
    return maxim;
  }
};
