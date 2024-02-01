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
  TreeNode *correctBinaryTree(TreeNode *root) {
    /* Sol) Use bfs and set of values to detect the wrong TreeNode*.
    When we do the bfs, first insert the right node and then left node.
    By doing this, after the node were visited that was pointed by invalid node,
    we can find that node's value from the set.
    */
    using ptt = pair<TreeNode *, pair<TreeNode *, bool>>;
    set<int> visited_vals;
    queue<ptt> nodes;
    nodes.push({root, {nullptr, false}});
    while (!nodes.empty()) {
      ptt curr = nodes.front();
      nodes.pop();
      if ((curr.first)->right != nullptr &&
          visited_vals.find((curr.first)->right->val) != visited_vals.end()) {
        (curr.first)->right = nullptr;
        if ((curr.first)->left != nullptr)
          delete (curr.first)->left;
        (curr.first)->left = nullptr;
        curr.first = nullptr;
        if (curr.second.second) {
          (curr.second.first)->right = nullptr;
        } else {
          (curr.second.first)->left = nullptr;
        }
        break;
      } else {
        visited_vals.insert((curr.first)->val);
        if ((curr.first)->right != nullptr)
          nodes.push({(curr.first)->right, {curr.first, true}});
        if ((curr.first)->left != nullptr)
          nodes.push({(curr.first)->left, {curr.first, false}});
      }
    }
    return root;
  }
};
