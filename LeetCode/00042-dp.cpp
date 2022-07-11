class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max_heights(height.size());
        int left_max = height[0];
        for(int i=0; i<height.size(); i++) {
            left_max = max(left_max, height[i]);
            left_max_heights[i] = left_max;
        }
        int rain_sum = 0;
        int right_max = height[height.size() - 1];
        for(int i=height.size()-1; i>=0; i--) {
            right_max = max(right_max, height[i]);
            int second_right_max = min(right_max, left_max_heights[i]);
            if (second_right_max > height[i]) {
                rain_sum += second_right_max - height[i];
            }
        }
        return rain_sum;
    }
};
