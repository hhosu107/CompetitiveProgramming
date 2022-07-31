class Solution {
public:
    int hist_maxarea(vector<int>& dp) {
        stack<int> s;
        s.push(-1);
        int maxarea = 0;
        for(int i=0; i<dp.size(); i++) {
            while(s.top() != -1 && dp[s.top()] >= dp[i]) {
                int curr_height = dp[s.top()];
                s.pop();
                int curr_width = i - s.top() - 1;
                maxarea = max(maxarea, curr_height * curr_width);
            }
            s.push(i);
        }
        while(s.top() != -1) {
            int curr_height = dp[s.top()];
            s.pop();
            int curr_width = dp.size() - s.top() - 1;
            maxarea = max(maxarea, curr_height * curr_width);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int max_area = 0;
        vector<int> dp(matrix[0].size()); // per each row, update the number of consecutive 1s before this cell in the each column.
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                // Update this row's historam using the last row's histogram.
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            max_area = max(max_area, hist_maxarea(dp)); // Note that, finiding maximum rectangular in the histogram needs O(m) time complexity.
        }
        return max_area;
    }
};

// Sol) 00084에서 histogram 높이들이 주어졌을 때 O(n) 안에 최대 넓이를 구하는
// 것을 응용하여, 각 row마다 col에서 출발하여 이전 row들을 보며 histogram의
// 높이를 업데이트하여, row의 histogram을 구하고 해당 histogram의 최대 넓이를
// 구한다.
