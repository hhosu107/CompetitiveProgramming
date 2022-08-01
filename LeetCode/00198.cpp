// Sol) leave 1 or 2 houses before robbing.

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size()); // dp[i] = robbing i, get the maximum revenue.
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        int max_dp = max(dp[0], dp[1]);
        if (nums.size() >= 3) {
            dp[2] = nums[0] + nums[2];
            max_dp = max(dp[2], max_dp);
        }
        for(int i=3; i<nums.size(); i++) {
            dp[i] = max({dp[i-2] + nums[i], dp[i-3] + nums[i]});
            max_dp = max(max_dp, dp[i]);
        }
        return max_dp;
    }
};
