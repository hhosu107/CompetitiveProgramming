class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> minmax(nums.size(), vector<int>(2));
        int max_until = nums[0];
        int min_until = nums[0];
        int result = max_until;
        for(int i=1; i<nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max({curr, max_until * curr, min_until * curr});
            min_until = min({curr, max_until * curr, min_until * curr}); // Why min_until continues the update whereas result delays by once?
            max_until = temp_max;
            result = max(max_until, result);
        }
        // min_until is free to update using above three values, whereas max_until is not the one that current min affects.
        return result;
    }
};
