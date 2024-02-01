class Solution {
public:
  void leftBoundaryOfBinaryTree(TreeNode *root, vector<int> &left, int height) {
    if (height == 0 && root->left == nullptr) {
      return;
    }
    if (root->left != nullptr) {
      if (height != 0) {
        left.push_back(root->val);
      }
      leftBoundaryOfBinaryTree(root->left, left, height + 1);
    } else if (root->right != nullptr) {
      left.push_back(root->val);
      leftBoundaryOfBinaryTree(root->right, left, height + 1);
    } else {
      return;
    }
  }
  void leavesBoundary(TreeNode *root, vector<int> &leaves, int height) {
    if (root->left == nullptr && root->right == nullptr) {
      if (height != 0) {
        leaves.push_back(root->val);
      }
      return;
    }
    if (root->left != nullptr) {
      leavesBoundary(root->left, leaves, height + 1);
    }
    if (root->right != nullptr) {
      leavesBoundary(root->right, leaves, height + 1);
    }
  }
  void reverseRightBoundaryOfBinaryTree(TreeNode *root, vector<int> &right,
                                        int height) {
    if (height == 0 && root->right == nullptr) {
      return;
    }
    if (root->right != nullptr) {
      reverseRightBoundaryOfBinaryTree(root->right, right, height + 1);
      if (height != 0) {
        right.push_back(root->val);
      }
    } else if (root->left != nullptr) {
      reverseRightBoundaryOfBinaryTree(root->left, right, height + 1);
      right.push_back(root->val);
    } else {
      return;
    }
  }
  vector<int> boundaryOfBinaryTree(TreeNode *root) {
    vector<int> boundary;
    boundary.push_back(root->val);
    vector<int> left, leaves, right;
    leftBoundaryOfBinaryTree(root, left, 0);
    leavesBoundary(root, leaves, 0);
    reverseRightBoundaryOfBinaryTree(root, right, 0);
    for (int l : left)
      boundary.push_back(l);
    for (int lf : leaves)
      boundary.push_back(lf);
    for (int r : right)
      boundary.push_back(r);
    return boundary;
  }
};
// Preorder traversal을 하면서 flag를 변화시켜가버리면 left/right를 따로 찾을
// 필요가 없다고는 하는데.. 그런 노력이 실무에서 필요한가?
