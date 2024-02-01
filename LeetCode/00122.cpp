class Solution {
  int maxProfit(vector<int> &prices) {
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1]) { // if there is any profit today, buy
                                       // previous day's stock and sell today.
        maxProfit += prices[i] - prices[i - 1];
      }
    }
    return maxProfit;
  }
};
