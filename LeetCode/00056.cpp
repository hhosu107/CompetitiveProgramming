class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> non_overlappings;
        stack<vector<int>> curr_intervals;
        for(vector<int> inte: intervals) {
            if (curr_intervals.empty()) {
                curr_intervals.push(inte);
            } else {
                vector<int> prev_inte = curr_intervals.top();
                curr_intervals.pop();
                if (inte[0] <= prev_inte[1]) {
                    vector<int> merged_inte{prev_inte[0], max(prev_inte[1], inte[1])};
                    curr_intervals.push(merged_inte);
                } else {
                    non_overlappings.push_back(prev_inte);
                    curr_intervals.push(inte);
                }
            }
        }
        if (!curr_intervals.empty()) {
            vector<int> last_inte = curr_intervals.top();
            curr_intervals.pop();
            non_overlappings.push_back(last_inte);
        }
        return non_overlappings;
    }
};
