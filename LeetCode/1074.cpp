class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // Sol) 1) Compute partial sums
        // 2) For each pair (x1, y1), (x2, y2), compute partial sum by (x1, y1) + (x2, y2) - (x1, y2) - (x2, y1). -> n^4?
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> partial_row_sum(m + 1, vector<int>(n + 1));
        vector<vector<int>> partial_sum(m + 1, vector<int>(n + 1));
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                partial_row_sum[i][j] = partial_row_sum[i][j-1] += matrix[i-1][j-1];
                partial_sum[i][j] = partial_sum[i-1][j] + partial_row_sum[i][j];
            }
        }
        
        int count = 0, curr_sum;
        unordered_map<int, int> hashmap; // key: possible partial_sum [r1, 0] to [r2, col]. value: number of occurrences. For each col, want to find curr_sum - target from this map, since then that means there are some partial matrices whose column = col_s is smaller than col, that [r1, col_s + 1] to [r2, col] has the value target.
        // Reduce 2D problem to 1D.
        // Fix two rows r1 and t2;
        // Compute 1D prefix sum for all matrices using [r1, ..., r2] rows.
        for(int r1 = 1; r1 <= m; r1++) {
            for(int r2 = r1; r2 <= m; r2++) {
                hashmap = unordered_map<int, int>();
                hashmap[0] = 1; // Empty matrix has sum 0.
                for(int col=1; col<=n; col++) {
                    curr_sum = partial_sum[r2][col] - partial_sum[r1 - 1][col];
                    count += hashmap[curr_sum - target]; // since curr_sum has not yet been added to the hashmap, this only finds 'residual matrices' that satisfies the description of line 17.
                    hashmap[curr_sum] += 1;
                }
            }
        }
        /* R^2C^2 : TLE
        int count = 0;
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=i; k<=m; k++) {
                    for(int l=j; l<=n; l++) {
                        int subsum = partial_sum[k][l] - partial_sum[k][j-1] - partial_sum[i-1][l] + partial_sum[i-1][j-1];
                        if (target == subsum) count += 1;
                    }
                }
            }
        }
        */
        return count;
    }
};
// 2 sum 문제와 같은 식으로 접근해야 time complexity를 최소화할 수 있다.
// 2 sum 문제도 target - value를 unordered_map에 count해두고 현재의 element와 저
// 값의 충돌이 얼마나 일어났는지 확인하는 것처럼,
// partial sum 역시 두 개의 row를 고정하고, [r1:r2][0:col] matrix들의 값만
// unordered_map의 key로서 count해서 저장해둔 다음, col이 1 늘어날 때마다
// curr_sum - target을 unordered_map에서 찾아서 한꺼번에 count해야 time
// complexity를 '# column'만큼 줄일 수 있다.
