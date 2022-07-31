class Solution {
public:
    int decoded_result(char curr) {
        return curr - '0';
    }
    int decoded_result(char prev, char curr) {
        return 10 * (prev - '0') + (curr - '0');
    }
    int numDecodings(string s) {
        int dp[2] = {0};
        char prev, curr;
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        prev = s[0];
        curr = s[1];
        dp[0] = 1;
        if (curr == '0' && decoded_result(prev, curr) > 26) return 0;
        dp[1] = (curr == '0' ? 1 : (decoded_result(prev, curr) > 26 ? 1 : 2));
        for(int i=2; i<s.length(); i++) {
            prev = curr;
            curr = s[i];
            int two_dec = (prev == '0' ? 99 : decoded_result(prev, curr));
            int one_dec = decoded_result(curr);
            int two_dec_dp = (two_dec > 26 ? 0 : dp[0]);
            int one_dec_dp = (one_dec == 0 ? 0 : dp[1]);
            if (two_dec_dp + one_dec_dp == 0) { // parsing impossible
                return 0;
            }
            dp[0] = dp[1];
            dp[1] = two_dec_dp + one_dec_dp;
        }
        return dp[1];
    }
};
