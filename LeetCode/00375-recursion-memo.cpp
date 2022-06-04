class Solution {
public:
    vector<vector<int>> memo;
    
    int dp(int l, int r){
        if(l >= r) return 0;
        if(memo[l][r] != -1) return memo[l][r];
        int res = INT32_MAX;
        for(int i = r; i >= (l + r) / 2; --i){
            int curr = i + max(dp(l, i-1), dp(i+1, r));
            if(curr > res) break;
            res = curr;
        }
        return memo[l][r] = res;
    }
    
    int getMoneyAmount(int n) {
        memo.assign(n + 1, vector<int>(n + 1, -1));
        return dp(1, n);
    }
};
