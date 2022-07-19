class Solution {
public:
    int lastStoneWeightII(vector<int> A) {
        bitset<1501> dp = {1};
        int sumA = 0;
        for (int a : A) {
            sumA += a;
            for (int i = min(1500, sumA); i >= a; --i)
                dp[i] = dp[i] + dp[i - a];
        }
        for (int i = sumA / 2; i >= 0; --i)
            if (dp[i]) return sumA - i - i;
        return 0;
    }
};
/*
 * Intuition
Same problem as:
Divide all numbers into two groups,
what is the minimum difference between the sum of two groups.
Now it's a easy classic knapsack problem.


Brief Prove
All cases of "cancellation of rocks" can be expressed by two knapsacks.
And the last stone value equals to the difference of these two knapsacks
It needs to be noticed that the opposite proposition is wrong.


Solution 1
Very classic knapsack problem solved by DP.
In this solution, I use dp to record the achievable sum of the smaller group.
dp[x] = 1 means the sum x is possible.

Time O(NS),
Space O(S) space, where S = sum(A).
*/
