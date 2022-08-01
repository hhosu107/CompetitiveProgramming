class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if (n <= 0 || k <= 0) return 0;
        if (2 * k > n) { // contiguous increment exists at most n/2 times.
            int res = 0;
            for(int i=1; i<n; i++)
                res += max(0, prices[i] - prices[i - 1]);
            return res;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1000000000)));
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];
        /*
        1. keep Holding stock: dp[i][j][1] = dp[i-1][j][1];
        2. keep not holding stock: dp[i][j][0] = dp[i-1][j][0];
        3. Buying when j > 0:
        dp[i][j][1] = dp[i-1][j-1][0] - prices[i]; // having nothing state (i-1, j-1, 0) to having one state (i, j, 1). lose prices[i].
        4. selling:
        dp[i][j][0] = dp[i-1][j][1] + prices[i] // having state (i-1, j, 1) to having nothing state (i, j, 0). get prices[i]. // Note that j doesn't increase since buying had a transaction already.
        combine 1/3 and 2/4.
        */
        for(int i=1; i<n; i++) {
            for(int j=0; j<=k; j++) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                if (j > 0)
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        int res = 0;
        for(int j=0; j<=k; j++)
            res = max(res, dp[n-1][j][0]); // Finally we have to sell the stock (since stock price is non-negative)
        return res;
        /*
        vector<vector<int>> transactions;
        int start = 0;
        int end = 0;
        for(int i=1; i<n; i++) {
            if (prices[i] >= prices[i - 1]) {
                end = i;
            } else {
                if (end > start) {
                    transactions.emplace_back(vector<int>{start, end});
                }
                start = i;
            }
        }
        if (end > start) {
            transactions.emplace_back(vector<int>{start, end});
        }
        while (transactions.size() > k) {
            int delete_index = 0;
            int min_delete_loss = INT_MAX;
            for (int i=1; i<transactions.size(); i++) {
                vector<int> t1 = transactions[i-1];
                vector<int> t2 = transactions[i];
                int profit_loss = prices[t1[1]] - prices[t2[0]];
                if (profit_loss < min_delete_loss) {
                    min_delete_loss = profit_loss;
                    delete_index = i;
                }
            }
            // check merge loss
            int merge_index = 0;
            int min_merge_loss = INT_MAX;
            for (int i = 1; i < transactions.size(); i++) {
                vector<int> t1 = transactions[i-1];
                vector<int> t2 = transactions[i];
                int profit_loss = prices[t1[1]] - prices[t2[0]];
                if (profit_loss < min_merge_loss) {
                    min_merge_loss = profit_loss;
                    merge_index = i;
                }
            }

            // delete or merge
            if (min_delete_loss <= min_merge_loss) {
                transactions.erase(transactions.begin() + delete_index);
            } else {
                transactions[merge_index-1][1] = transactions[merge_index][1];
                transactions.erase(transactions.begin() + merge_index);
            }
        }
        int res = 0;
        for(vector<int> t: transactions)
            res += prices[t[1]] - prices[t[0]];
        return res;
        */
    }
};
