class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> smaller;
        int index = 0;
        vector<int> next_greater(nums.size(), -1);
        for(int i=0; i<2 * nums.size(); i++) {
            while (!smaller.empty() && nums[smaller.top() % nums.size()] < nums[i % nums.size()]) {
                int top = smaller.top();
                smaller.pop();
                if (next_greater[top % nums.size()] == -1) next_greater[top % nums.size()] = nums[i % nums.size()];
            }
            smaller.push(i);
        }
        return next_greater;
    }
};
