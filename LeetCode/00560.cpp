class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> partial_sums;
        partial_sums[0] = 1;
        int curr_sum = 0;
        int count = 0;
        for(int n: nums) {
            curr_sum += n;
            count += partial_sums[curr_sum - k];
            partial_sums[curr_sum] += 1;
        }
        return count;
    }
};

