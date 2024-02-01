class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {

    int n = prices.size();
    if (n <= 0 || k <= 0)
      return 0;
    if (2 * k > n) { // contiguous increment exists at most n/2 times.
      int res = 0;
      for (int i = 1; i < n; i++)
        res += max(0, prices[i] - prices[i - 1]);
      return res;
    }
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(k + 1, vector<int>(2, -1000000000)));
    dp[0][0][0] = 0;
    dp[0][1][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        if (j > 0)
          dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }
    int res = 0;
    for (int j = 0; j <= k; j++)
      res = max(res, dp[n - 1][j][0]); // Finally we have to sell the stock
                                       // (since stock price is non-negative)
    return res;
  }
};
