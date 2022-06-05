/* Wildcard.
 * I had a trouble to solve this since 2013, but now I understood with the
 * explanation.
 */

class Solution {
public:
    vector<vector<int>> memoize;
    bool isMatch(string s, string p) {
        memoize = vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, -1));
        return (dp(0, 0, s, p) == 1);
    }
    
    int dp(int si, int pi, string &s, string &p) {
        if (memoize[si][pi] != -1) {
            return memoize[si][pi];
        }
        bool ans;
        if (pi == p.length()) {
            ans = (si == s.length()); // pattern consumed exactly as string consumed
        } else {
            // match occurs when:
            // si < s.length() and
            // either s[si] == p[pi] or p[pi] == '.'.
            bool first_match = (si < s.length() && (s[si] == p[pi] || p[pi] == '.'));
            // When this match occurs, see the next character of the pattern.
            // If it is a wildcard, we have to select to skip that or don't skip that.
            // If we don't skip, reuse p[pi] as the padding of '*'.
            if (pi + 1 < p.length() && p[pi + 1] == '*') {
                ans = (dp(si, pi + 2, s, p) || (first_match && dp(si + 1, pi, s, p)));
            } else {
                ans = (first_match && dp(si + 1, pi + 1, s, p));
            }
        }
        memoize[si][pi] = (ans ? 1 : 0);
        return memoize[si][pi];
    }
};
