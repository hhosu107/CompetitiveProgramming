class Solution {
public:
    vector<bool> visitible;
    bool canJump(vector<int>& nums) {
        /* Slower BFS
        int len = nums.size();
        if (len == 1) return true;
        visitible = vector<bool>(len, false);
        queue<int> visited_index;
        visited_index.push(0);
        visitible[0] = true;
        while(!visited_index.empty()) {
            int curr = visited_index.front();
            visited_index.pop();
            for(int i=1; i<=nums[curr]; i++) {
                if (i + curr >= len) continue;
                if (i + curr == len - 1) return true;
                if (!visitible[i + curr]) {
                    visitible[i + curr] = true;
                    visited_index.push(i + curr);
                }
            }
        }
        return false;
        */
        // Greedy backward: last cell can reach last cell, prev cells...
        int len = nums.size();
        int lastPos = len - 1;
        for(int i=len - 1; i>=0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i; // if lastPos is able to be reached from i, search i whether it is reachable.
            }
        }
        return lastPos == 0; // since 0th index is the starting point, lastPos == 0 means len - 1 is reachable.
    }
};
