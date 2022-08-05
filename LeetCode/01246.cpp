class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int len = arr.size();
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
        for(int i=0; i<len; i++) {
            for(int j=i; j<len; j++)
                dp[i][j] = j - i + 1;
        }
        for(int i=1; i<len; i++) {
            if (arr[i-1] == arr[i]) dp[i-1][i] = 1;
        }
        // Construct DP table from end to start.
        // Chec
        for(int i=len - 3; i>=0; i--) {
            for(int j=i + 2; j<len; j++) {
                if (arr[i] == arr[j]) // base case: if A can be factored with k operations (the last operation deletes the palindrome y itself), xAx can be factored with k operations (the last operation deletes the palindrome xyx).
                    dp[i][j] = dp[i + 1][j-1];
                for(int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]); // Similar to the matrix multiplication. Either factor xAx in the same way as A did, or split into two factors.
            }
        }
        return dp[0][len-1];
    }
};
