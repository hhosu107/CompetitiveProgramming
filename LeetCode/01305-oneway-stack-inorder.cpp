/**
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
public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    // Iterative solution: use stack to simulate inorder traversal, and select
    // the next one to move on.
    stack<TreeNode *> tree1;
    stack<TreeNode *> tree2;
    vector<int> ret;
    while (root1 != nullptr || root2 != nullptr || !tree1.empty() ||
           !tree2.empty()) {
      // do full left traversal
      while (root1 != nullptr) {
        tree1.push(root1);
        root1 = root1->left;
      }
      while (root2 != nullptr) {
        tree2.push(root2);
        root2 = root2->left;
      }
      if (tree2.empty() ||
          (!tree1.empty() &&
           tree1.top()->val <= tree2.top()->val)) { // tree1's value is smaller;
                                                    // find the next element.
        root1 = tree1.top();
        tree1.pop();
        ret.emplace_back(root1->val);
        root1 = root1->right;
      } else { // tree2's value is smaller or tree1 is empty. find the next
               // element of tree2.
        root2 = tree2.top();
        tree2.pop();
        ret.emplace_back(root2->val);
        root2 = root2->right;
      }
    }
    return ret;
  }
};
