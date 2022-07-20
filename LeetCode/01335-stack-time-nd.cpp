#include<vector>
#include<stack>
using namespace std;
int minDifficulty(vector<int>& A, int D) {
    int n = A.size();
    if (n < D) return -1;
    vector<int> dp(n, 1000), dp2(n), stack;
    for (int d = 0; d < D; ++d) {
        stack.clear();
        for (int i = d; i < n; i++) {
            dp2[i] = i ? dp[i - 1] + A[i] : A[i];
            while (stack.size() && A[stack.back()] <= A[i]) {
                int j = stack.back(); stack.pop_back();
                dp2[i] = min(dp2[i], dp2[j] - A[j] + A[i]);
            }
            if (stack.size()) {
                dp2[i] = min(dp2[i], dp2[stack.back()]);
            }
            stack.push_back(i);
        }
        swap(dp, dp2);
    }
    return dp[n - 1];
}
/*
Solution 4 with the stack is brilliant. I spend a lot of time understanding it.
Here is my understanding:
The reason why the stack can speed up is that we don't have to check every possible cut off (the value of j in solution 2/3).
The stack keeps the index of monotonically decreasing number in A. When checking A[i], assuming that the last number that larger than A[i] is A[t] (stack[-1]=t after poping), there are two possible situations:

For possible cut off index m in A[t: i]: t<=m <i:
We need to check possible cut off. And the corresponding code is in the while loop: " j = stack.pop() dp2[i] = min(dp2[i], dp2[j] - A[j] + A[i])"
Here we only check those items pop from the stack (they have a smaller index but larger value). we can see that the items pop before this loop were smaller, they were dominant by the items left in the stack. So we don't have to check those items.
For possile cut off index m in A[:t]: m <t
since A[t] is the last number that larger than A[i], we know A[t] = max(A[t:i]), for any index m before t(m<t), we have max(A[m:i]) = max(A[m:t]) : we can directly "dp2[i] = min(dp2[i], dp2[stack[-1]])"
Remeber that in 2D Array: dp[d][i] means the min difficulty in d days for i jobs, it equals dp[d][i] = dp[d][t] (t < i so dp[d][t] should have already been caculated)
*/

