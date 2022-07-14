class Solution {
public:
    const int INF = 10000000;
    vector<vector<int>> costs; // saves the cost between house[i] and house[j] with "only 1 mailbox"
    vector<vector<int>> mem; // saves the solution.
    int minDistance(vector<int>& houses, int k) {
        int len = houses.size();
        costs = vector<vector<int>>(len, vector<int>(len, 0));
        mem = vector<vector<int>>(k + 1, vector<int>(len, -1));
        if (k == len) return 0;
        sort(houses.begin(), houses.end());
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                int medianPos = houses[(i+j) / 2]; // prove: i == j: trivial. i == j + 1: one of them. j - i == 2*k: i + k. j - i == 2*k + 1: i + k or i + k + 1.
                for(int m=i; m<=j; m++) {
                    costs[i][j] += abs(medianPos - houses[m]);
                }
            }
        }
        return house_dp(houses, len, k, 0);
    }
    
    int house_dp(vector<int> &houses, int len, int k, int i) { // len: houses' length. k: remaining mailboxes, i: mailboxes must be placed at or after ith house.
        if (k == 0 && i == len) return 0; // we searched all houses and placed all mailboxes.
        if (k == 0 || i == len) return INF; // we failed to place all mailboxes or failed to search all houses.
        if (mem[k][i] != -1) return mem[k][i]; // Already computed dp where k mailboxes left and search from ith house is needed.
        int ans = INF;
        for (int j=i; j<len; j++) {
            ans = min(ans, costs[i][j] + house_dp(houses, len, k - 1, j + 1)); // we cover house[i]~house[j] with a single mailbox. Thus decrease mailbox by 1, and search house from j + 1.
        }
        mem[k][i] = ans;
        return mem[k][i];
    }
};
// Recursive + memoize DP.
// Ideas are written
