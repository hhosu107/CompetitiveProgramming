#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

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
int maximalRectangle(vector<string>& matrix) {
    if (matrix.size() == 0) return 0;
    int max_area = 0;
    vector<int> dp(matrix[0].length()); // per each row, update the number of consecutive 1s before this cell in the each column.
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].length(); j++) {
            // Update this row's historam using the last row's histogram.
            dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
        }
        vector<int> sorted_dp(dp); // To get the maximum area of the histogram if the sorting is allowed, just sort this histogram and compute the maximal area from each column to the rightmost column(n).
        sort(sorted_dp.begin(), sorted_dp.end());
        // TLE in sorting.
        max_area = max(max_area, hist_maxarea(sorted_dp)); // Note that, finiding maximum rectangular in the histogram needs O(m) time complexity.
    }
    return max_area;
}

int main() {
    int n, m;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    vector<string> matrix(n);
    for(string &mm: matrix)
        cin >> mm;
    cout << maximalRectangle(matrix) << '\n';
    return 0;
}
