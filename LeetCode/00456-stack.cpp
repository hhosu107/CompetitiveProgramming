class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        stack<int> right_numbers = stack<int>();
        vector<int> mins(nums.size(), nums[0]);
        for(int i=1; i<nums.size(); i++)
            mins[i] = min(mins[i-1], nums[i]);
        for(int j=nums.size() - 1; j>=0; j--){
            while(!right_numbers.empty() && right_numbers.top() <= mins[j]) {
                right_numbers.pop(); // filter out numbers that is smaller than mins[j]
            }
            // Now the first element of the stack must be bigger than mins[j]. Thus, compare that element with nums[j].
            if (!right_numbers.empty() && right_numbers.top() < nums[j]) {
                return true; // then, right_numbers.top() > mins[j], right_numbers.top().idx > j > mins[j].idx, right_numbers.top() < nums[j]. PROFIT
            }
            right_numbers.push(nums[j]);
        }
        return false;
    }
};
