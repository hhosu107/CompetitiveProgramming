class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // Sol) for each cell, compute min (n, s, e, w) and add min(n, s, e, w) - cell to the answer.
        // n watches from n-1th col to 0th col; south watches from 0th col to n-1 col; west watches from 0 to n-1 row; east watches from n - 1 row.
        int ans = 0;
        int len = grid.size();
        vector<int> n(len), s(len), e(len), w(len);
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                n[len - 1 - j] = max(n[len - 1 - j], grid[i][j]);
                s[j] = max(s[j], grid[i][j]);
                e[len - 1 - i] = max(e[len - 1 - i], grid[i][j]);
                w[i] = max(w[i], grid[i][j]);
            }
        }
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                ans += min({n[len - 1 - j], s[j], e[len - 1 - i], w[i]}) - grid[i][j];
            }
        }
        return ans;
    }
};
