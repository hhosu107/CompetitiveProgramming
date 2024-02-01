class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    // Sol) Use 1 deque or 2 stacks.
    // 1) deque: must save it's level as the deque element.
    // 2) stacks: don't have to save it's level.
    stack<TreeNode *> zigzag[2];
    vector<vector<int>> zigzaged_values = vector<vector<int>>();
    if (root == nullptr)
      return zigzaged_values;
    zigzag[0].push(root);
    int prev_level = 0;
    int curr_level_count = 0;
    do {
      curr_level_count = 0;
      vector<int> prev_level_output;
      while (!zigzag[prev_level % 2].empty()) {
        TreeNode *curr = zigzag[prev_level % 2].top();
        prev_level_output.push_back(curr->val);
        zigzag[prev_level % 2].pop();
        if (prev_level % 2 == 0) {
          if (curr->left != nullptr) {
            zigzag[(prev_level + 1) % 2].push(curr->left);
            curr_level_count += 1;
          }
          if (curr->right != nullptr) {
            zigzag[(prev_level + 1) % 2].push(curr->right);
            curr_level_count += 1;
          }
        } else {
          if (curr->right != nullptr) {
            zigzag[(prev_level + 1) % 2].push(curr->right);
            curr_level_count += 1;
          }
          if (curr->left != nullptr) {
            zigzag[(prev_level + 1) % 2].push(curr->left);
            curr_level_count += 1;
          }
        }
      }
      prev_level += 1;
      zigzaged_values.push_back(prev_level_output);
    } while (curr_level_count > 0);
    return zigzaged_values;
  }
};
