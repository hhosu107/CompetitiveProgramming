/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
// Time complexity: O(n log n), space complexity: O(n).
// If given intervals per employee are not sorted, this one only works.
// But since they are sorted per users, other method (merging k users) dominates
// this one.
class Solution {
public:
    // Sol) Event based system.
    map<int, int> delta;
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        for(vector<Interval> employee: schedule) {
            for(Interval i: employee) {
                delta[i.start] += 1;
                delta[i.end] -= 1;
            }
        }
        vector<Interval> free_times;
        int curr_users = 0;
        int prev_freed_time = -1;
        for (auto const& [k, v]: delta) {
            if (curr_users == 0 && v > 0) {
                if (prev_freed_time > 0) {
                    free_times.push_back(Interval(prev_freed_time, k));
                }
            }
            curr_users += v;
            if (curr_users == 0) {
                prev_freed_time = k;
            }
        }
        return free_times;
    }
};
