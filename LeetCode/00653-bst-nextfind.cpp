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
  bool hasNext(stack<TreeNode *> &checker_stack) {
    return !checker_stack.empty();
  }
  void pushLeft(TreeNode *root, stack<TreeNode *> &leftmost_stack) {
    while (root != nullptr) {
      leftmost_stack.push(root);
      root = root->left;
    }
  }
  TreeNode *nextLeft(stack<TreeNode *> &leftmost_stack) {
    TreeNode *root = leftmost_stack.top();
    leftmost_stack.pop();
    pushLeft(root->right, leftmost_stack);
    return root;
  }
  void pushRight(TreeNode *root, stack<TreeNode *> &rightmost_stack) {
    while (root != nullptr) {
      rightmost_stack.push(root);
      root = root->right;
    }
  }
  TreeNode *nextRight(stack<TreeNode *> &rightmost_stack) {
    TreeNode *root = rightmost_stack.top();
    rightmost_stack.pop();
    pushRight(root->left, rightmost_stack);
    return root;
  }
  bool findTarget(TreeNode *root, int k) {
    // Sol) Prepare two stacks.
    // First one: containing minimum elements.
    // When the top element of the stack has left child, insert that left child.
    // If the top element of the stack doesn't have the left child, stop there,
    // pop the element, and insert the right child node if exists. At the next
    // step, iterate that.
    stack<TreeNode *> leftmost_stack, rightmost_stack;
    pushLeft(root, leftmost_stack);
    pushRight(root, rightmost_stack);
    TreeNode *smallest_elmt = nextLeft(leftmost_stack);
    TreeNode *biggest_elmt = nextRight(rightmost_stack);
    while (smallest_elmt->val < biggest_elmt->val) {
      int curr_sum = smallest_elmt->val + biggest_elmt->val;
      if (curr_sum == k) {
        return true;
      }
      if (curr_sum < k) {
        smallest_elmt = nextLeft(leftmost_stack);
      } else {
        biggest_elmt = nextRight(rightmost_stack);
      }
    }
    if (smallest_elmt != biggest_elmt &&
        smallest_elmt->val + biggest_elmt->val == k) {
      return true;
    }
    return false;
  }
};
