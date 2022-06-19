class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> colors_bucket(3, vector<int>());
        vector<vector<int>> colors_idx(3, vector<int>());
        for(int i=0; i<colors.size(); i++) {
            colors_bucket[colors[i] - 1].push_back(colors[i]);
            colors_idx[colors[i] - 1].push_back(i);
        }
        vector<int> res;
        for(int i=0; i<queries.size(); i++) {
            int color_idx = queries[i][1] - 1;
            if (colors_idx[color_idx].size() == 0) {
                res.push_back(-1);
                continue;
            }
            if (colors[queries[i][0]] == color_idx + 1) {
                res.push_back(0);
                continue;
            }
            auto left_idx = lower_bound(colors_idx[color_idx].begin(), colors_idx[color_idx].end(), queries[i][0]);
            auto right_idx = upper_bound(colors_idx[color_idx].begin(), colors_idx[color_idx].end(), queries[i][0]);
            int left_value;
            int right_value;
            if (right_idx == colors_idx[color_idx].end()) {
                right_idx--;
                left_value = right_value = colors_idx[color_idx][right_idx - colors_idx[color_idx].begin()];
            } else if (left_idx == colors_idx[color_idx].end()) {
                left_value = right_value = colors_idx[color_idx][right_idx - colors_idx[color_idx].begin()];
            } else {
                if (left_idx - colors_idx[color_idx].begin() > 0) {
                    left_idx--;
                }
                left_value = colors_idx[color_idx][left_idx - colors_idx[color_idx].begin()];
                right_value = colors_idx[color_idx][right_idx - colors_idx[color_idx].begin()];
            }
            int left_dist = abs(queries[i][0] - left_value);
            int right_dist = abs(queries[i][0] - right_value);
            res.push_back(min(left_dist, right_dist));
        }
        return res;
    }
};
