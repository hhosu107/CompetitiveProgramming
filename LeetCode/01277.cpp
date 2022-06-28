class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Sol) Compute the maximum size of square starting from [i][j]. Then sum all of them.
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=m-1; i>=0; i--)
            dp[n-1][i] = matrix[n-1][i];
        for(int i=n-1; i>=0; i--)
            dp[i][m-1] = matrix[i][m-1];
        for(int k = 1; k<=min(n-1, m-1); k++) {
            for(int i=n-1-k; i>=0; i--) {
                if (matrix[i][m-1-k] == 1) {
                    dp[i][m-1-k] = min({dp[i+1][m-k], dp[i+1][m-1-k], dp[i][m-k]}) + 1;
                }
            }
            for(int i=m-1-k; i>=0; i--) {
                if (matrix[n-1-k][i] == 1) {
                    dp[n-1-k][i] = min({dp[n-k][i+1], dp[n-k][i], dp[n-1-k][i+1]}) + 1;
                }
            }
        }
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
// Follow up: Could I remove the added dp matrix?
// Answer: it should be possible. Since matrix[i+1][m-k], matrix[i+1][m-1-k],
// matrix[i][m-k], matrix[n-k][i+1], matrix[n-k][i], matrix[n-1-k][i+1] won't
// contribute anymore. (But I have to change the loop i=m-1-k to 0 to i=m-2-k to
// 0.
