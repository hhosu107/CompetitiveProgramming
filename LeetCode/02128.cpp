class Solution {
public:
    // 1. flip order does not matter.
    // 2. thus, only if row flipping makes the identical patterns for every row, it can be 0.
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 || n == 1) return true;
        vector<int> ref_row(grid[0]);
        vector<int> ref_row_inverted(grid[0].size());
        for(int i=0; i<ref_row.size(); i++) {
            ref_row_inverted[i] = 1 - ref_row[i];
        }
        for(int i=1; i<m; i++) {
            bool identical = true, invert_identical = true;
            for(int j=0; j<n; j++) {
                if (ref_row[j] != grid[i][j]) identical = false;
                if (ref_row_inverted[j] != grid[i][j]) invert_identical = false;
            }
            if (!identical && !invert_identical) return false;
        }
        return true;
    }
};
// Idea: negation does not matter on the order of execution, if the number of
// negation is identical for two sequences.
// Thus, we first perform row operations first and column operations.
// to make all elements 0 with 0 or 1 column operation for each column, every
// rows must be identical in the pattern (that is, either identical or
// (1-pattern) identical.
