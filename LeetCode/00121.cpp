class Solution {
    int maxProfie(vector<int>& prices) {
        int minprice = 2147483647;
        int maxprofit = 0;
        for(int i=0; i<prices.size(); i++) {
            if (minprice > prices[i])
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit) {
                maxprofit = prices[i] - minprice;
            }
        }
        return maxprofit;
    }
};
