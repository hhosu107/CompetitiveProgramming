class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        // Condition: given previous constructions either from [i-1][j] or [i][j-1], can we construct dp[i][j] with using i-1th character of s1 or j-1th character of s2 for s3[i+j-1]th character?
        /*
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1));
        for(int i=0; i<=s1.length(); i++) {
            for(int j=0; j<=s2.length(); j++) {
                if (i == 0 && j == 0) dp[i][j] = true; // none of characters are used.
                else if (i == 0) {
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i + j - 1]; // can s3[0:j] be constructed with s2[0:j]?
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i + j - 1]; // can s3[0:i] be constructed with s1[0:i]?
                } else {
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i + j - 1]) || (dp[i][j-1] && s2[j-1] == s3[i + j - 1]); // can s3[i + j - 1] be constructed with either s1[i-1] or s2[i-1] where previous constructions were made?
                }
            }
        }
        return dp[s1.length()][s2.length()];
        */
        vector<bool> dp(s2.length() + 1);
        for(int i=0; i<=s1.length(); i++) {
            for(int j=0; j<=s2.length(); j++) {
                if (i == 0 && j == 0) dp[j] = true; // none of characters are used.
                else if (i == 0) {
                    dp[j] = dp[j-1] && s2[j-1] == s3[i + j - 1]; // can s3[0:j] be constructed with s2[0:j]?
                } else if (j == 0) {
                    dp[j] = dp[j] && s1[i-1] == s3[i + j - 1]; // can s3[0:i] be constructed with s1[0:i]?
                } else {
                    dp[j] = (dp[j] && s1[i-1] == s3[i + j - 1]) || (dp[j-1] && s2[j-1] == s3[i + j - 1]); // can s3[i + j - 1] be constructed with either s1[i-1] or s2[i-1] where previous constructions were made?
                }
            }
        }
        return dp[s2.length()];
    }
};
