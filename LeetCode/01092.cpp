class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        string lcs = LCSString(str1, str2);
        int len1_idx = 0, len2_idx = 0;
        string ans = "";
        for(char c: lcs) {
            while (c != str1[len1_idx]) {
                ans += str1[len1_idx];
                len1_idx++;
            }
            while (c != str2[len2_idx]) {
                ans += str2[len2_idx];
                len2_idx++;
            }
            ans += c;
            len1_idx++;
            len2_idx++;
        }
        ans += str1.substr(len1_idx);
        ans += str2.substr(len2_idx);
        return ans;
    }
    string LCSString(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        vector<vector<int>> dir(len1 + 1, vector<int>(len2 + 1));
        /*
        for(int i=0; i<len2; i++) {
            dp[len1][i] = 0;
            dir[len1][i] = 1;
        }
        for(int i=0; i<len1; i++) {
            dp[i][len2] = 0;
            dir[i][len2] = 2;
        }
        // I cannot understand why this 'reversed' construction does not hold.
        for(int i=len1 - 1; i>=0; i--) {
            for(int j=len2 - 1; j>=0; j--) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    dir[i][j] = 3;
                }
                else if (dp[i + 1][j] > dp[i][j + 1]) {
                    dp[i][j] = dp[i + 1][j];
                    dir[i][j] = 2;
                } else {
                    dp[i][j] = dp[1][j + 1];
                    dir[i][j] = 1;
                }
            }
        }
        int x = 0, y = 0;
        string ans = "";
        while (x < len1 && y < len2) {
            if (dp[x][y] == dp[x][y + 1]) {
                y++;
            } else if (dp[x][y] == dp[x + 1][y]) {
                x++;
            } else {
                ans += str1[x];
                x++;
                y++;
            } 
        }
        return ans;
        */
        for(int i=0; i<len1; i++) {
            for(int j=0; j<len2; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                if (str1[i] == str2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        int x = len1, y = len2;
        string rev_ans;
        while(x > 0 && y > 0) {
            if (dp[x - 1][y] == dp[x][y]) {
                x--;
            } else if (dp[x][y-1] == dp[x][y]) {
                y--;
            } else {
                rev_ans += str1[x-1];
                x--;
                y--;
            }
        }
        reverse(rev_ans.begin(), rev_ans.end());
        return rev_ans;
    }
};

// Shortest supersequence = longest common subsequence.
// This relation is same as gcd / lcm.
