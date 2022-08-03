class Solution {
public:
    unordered_map<int, int> identical_count;
    int numIdenticalPairs(vector<int>& nums) {
        for(int n: nums)
            identical_count[n] += 1;
        int cnt = 0;
        for(const auto &[n, c]: identical_count)
            cnt += c * (c - 1) / 2;
        return cnt;
    }
};
