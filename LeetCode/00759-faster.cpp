// Time complexity: O(n log k), additional Space complexity: O(k) (n: #
// intervals, k: # users)
// When this solution dominates whole map solution?:
// - small number of users, very large number of intervals per user
// - few collisions between interval ends
// When this solution is efficient than map solution?:
// - any time since map solution requires O(n) additional space, but this one
// requires O(k) additional space.
class Solution {
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedule) {
        using pii = pair<int, int>;
        auto comp = [&schedule](const pair<int, int> &a, const pair<int, int> &b) {
            if (schedule[a.first][a.second].start != schedule[b.first][b.second].start) {
                return schedule[a.first][a.second].start > schedule[b.first][b.second].start;
            }
            return schedule[a.first][a.second].end > schedule[b.first][b.second].end;
        }
        priority_queue, decltype(comp)> pq(comp);
        for (int i=0; i<schedule.size(); i++)
            pq.push({i, 0});
        vector<Interval> res;
        int prev = schedule[pq.top().first][pq.top().second].start;
        while(!pq.empty()) {
            pii index = pq.top();
            pq.pop();
            Interval interval = schedule[index.first][index.second];
            if (interval.start > prev) {
                res.push_back({prev, interval.start});
            }
            prev = max(prev, interval.end);
            if (schedule[index.first].size() > index.second + 1) {
                pq.push({index.first, index.second + 1});
            }
        }
        return res;
    }
};
