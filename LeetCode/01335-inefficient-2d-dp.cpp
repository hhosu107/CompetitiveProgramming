class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if (len < d) return -1;
        // Sol) DP once more?
        // 1) Construct cost[i][j]: for i<=j, this is the cost for finishing jobs between i to j. It needs n^2.
        vector<vector<int>> cost(len, vector<int>(len));
        for(int i=0; i<len; i++) {
            int max_diff = 0;
            for(int j=i; j<len; j++) {
                max_diff = max(max_diff, jobDifficulty[j]);
                cost[i][j] = max_diff;
            }
        }
        // 2) conduct dp[x][i] = min(cost[i][j] + dp[x+1][j+1]) for i in x to len - (d - x), j in i to len - (d - x) inclusive.
        vector<vector<int>> dp(d + 1, vector<int>(len + 1, 1000000));
        for(int i=0; i<=d; i++) dp[i][len] = 0;
        for(int i=0; i<len; i++) dp[d][len] = 0;
        for(int x=d-1; x>=0; x--) {
            for(int i=len - (d - x); i >= x; i--) {
                for(int j=len - (d - x); j >= i; j--) {
                    dp[x][i] = min(dp[x][i], cost[i][j] + dp[x+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
