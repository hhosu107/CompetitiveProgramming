class Solution {
public:
    int numSquaresMemoized(int n, vector<int> &count) {
        if (count[n] != 10001) return count[n];
        int min_cnt = 10001;
        for(int i=1; i*i<=n; i++) {
            min_cnt = min(min_cnt, 1 + numSquaresMemoized(n - i * i, count));
        }
        count[n] = min_cnt;
        return count[n];
    }
    int numSquares(int n) {
        vector<int> count(n + 1, 10001);
        count[0] = 0;
        int result = numSquaresMemoized(n, count);
        return result;
    }
};
