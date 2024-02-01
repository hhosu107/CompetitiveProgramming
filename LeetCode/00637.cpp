class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    if (root == nullptr)
      return ans;
    using ll = long long;
    vector<ll> level_nodes_sum;
    vector<ll> level_nodes_count;
    using pti = pair<TreeNode *, int>;
    queue<pti> level_nodes;
    level_nodes.push({root, 0});
    while (!level_nodes.empty()) {
      pti top = level_nodes.front();
      level_nodes.pop();
      if (top.first == nullptr)
        continue;
      if (top.second == level_nodes_sum.size()) {
        level_nodes_sum.push_back(0LL);
        level_nodes_count.push_back(0LL);
      }
      level_nodes_sum[top.second] += (ll)(top.first->val);
      level_nodes_count[top.second] += 1LL;
      level_nodes.push({top.first->left, top.second + 1});
      level_nodes.push({top.first->right, top.second + 1});
    }
    for (int i = 0; i < level_nodes_sum.size(); i++) {
      ans.push_back((double)level_nodes_sum[i] / (double)level_nodes_count[i]);
    }
    return ans;
  }
};
