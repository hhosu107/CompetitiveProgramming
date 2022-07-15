using pti = pair<TreeNode*, int>;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        queue<pti> q;
        map<int, vector<int>> height_vals;
        q.push({root, 0});
        while(!q.empty()) {
            pti t = q.front();
            q.pop();
            if (height_vals.find(t.second) == height_vals.end()) {
                height_vals[t.second] = vector<int>({(t.first)->val});
            } else {
                height_vals[t.second].push_back((t.first)->val);
            }
            if ((t.first)->left != NULL) {
                q.push({(t.first)->left, t.second + 1});
            }
            if ((t.first)->right != NULL) {
                q.push({(t.first)->right, t.second + 1});
            }
        }
        vector<vector<int>> zig = vector<vector<int>>();
        for(auto val: height_vals) {
            vector<int> vals = val.second;
            if (val.first % 2 == 1) reverse(vals.begin(), vals.end());
            zig.push_back(vals);
        }
        return zig;
    }
};
