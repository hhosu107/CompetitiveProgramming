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
  bool findPath(TreeNode *root, vector<TreeNode *> &path, int k) {
    // base case
    if (root == NULL)
      return false;

    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root);

    // See if the k is same as root's key
    if (root->val == k)
      return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
      return true;

    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
  }

  // Returns LCA if node n1, n2 are present in the given binary tree,
  // otherwise return -1
  string findLCADirections(TreeNode *root, int n1, int n2) {
    // to store paths to n1 and n2 from the root
    vector<TreeNode *> path1, path2;

    // Find paths from root to n1 and root to n2. If either n1 or n2
    // is not present, return -1
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
      return "";

    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
      if (path1[i] != path2[i])
        break;
    // starting from i-1, convert path1's remaining characters to U and insert
    // directions for path2.
    string directions = "";
    for (int j = i - 1; j < path1.size() - 1; j++) {
      directions += "U";
    }
    for (int j = i - 1; j < path2.size() - 1; j++) {
      if (path2[j + 1] == path2[j]->left)
        directions += "L";
      else
        directions += "R";
    }
    return directions;
  }

  // Sol) Find LCA. Save root -> ... -> LCA -> leftNode, root-> ... -> LCA ->
  // ... -> rightNode. Then write "U" [leftNode - LCA] times, write either "L"
  // or "R" by comparing path[j] with either path[j-1]->left or
  // path[j-1]->right.
  string getDirections(TreeNode *root, int startValue, int destValue) {
    return findLCADirections(root, startValue, destValue);
  }
};
