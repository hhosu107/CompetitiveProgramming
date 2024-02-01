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
  void removeNode(set<TreeNode *> &forest, int delete_val) {
    for (auto it = forest.begin(); it != forest.end(); it++) {
      if ((*it)->val == delete_val) {
        if ((*it)->left != nullptr)
          forest.insert((*it)->left);
        if ((*it)->right != nullptr)
          forest.insert((*it)->right);
        forest.erase(it);
        return;
      }
      queue<pair<TreeNode *, TreeNode *>> nodes;
      nodes.push({nullptr, *it});
      while (!nodes.empty()) {
        pair<TreeNode *, TreeNode *> curr = nodes.front();
        nodes.pop();
        if ((curr.second)->val == delete_val) {
          if ((curr.second)->left != nullptr)
            forest.insert((curr.second)->left);
          if ((curr.second)->right != nullptr)
            forest.insert((curr.second)->right);
          if (((curr.first)->left) != nullptr &&
              ((curr.first)->left)->val == delete_val) {

            (curr.first)->left = nullptr;
          }
          if (((curr.first)->right) != nullptr &&
              ((curr.first)->right)->val == delete_val) {
            // auto it = forest.find(curr.first);
            (curr.first)->right = nullptr;
          }
          return;
        }
        if ((curr.second)->left != nullptr) {
          nodes.push({curr.second, (curr.second)->left});
        }
        if ((curr.second)->right != nullptr) {
          nodes.push({curr.second, (curr.second)->right});
        }
      }
    }
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    set<TreeNode *> forest;
    forest.insert(root);
    for (int i = 0; i < to_delete.size(); i++) {
      removeNode(forest, to_delete[i]);
    }
    vector<TreeNode *> vec_forest;
    for (TreeNode *forest_root : forest)
      vec_forest.push_back(forest_root);
    return vec_forest;
  }
};
