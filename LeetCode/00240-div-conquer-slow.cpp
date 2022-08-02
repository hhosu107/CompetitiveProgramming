class Solution {
public:
    // Quadratic search.
    // if matrix[i][j] < target, we know that matrix[0][0] ~ matrix[i][j] is not the interest of us.
    // if matrix[i][j] > target, we know that matrix[i][j] ~ matrix[matrix.size() - 1][matrix[0].size() - 1] is not the interest of us.
    // For each iteration, we throw out 1/4 of the search area.
    // thus, log_(4/3) method.
    bool searchMatrixQuad(vector<vector<int>>& matrix, int x_lo, int x_hi, int y_lo, int y_hi, int target) {
        if (x_lo >= x_hi || y_lo >= y_hi) return false;
        int x_mid = (x_lo + x_hi) / 2, y_mid = (y_lo + y_hi) / 2;
        if (target == matrix[x_mid][y_mid]) return true;
        if (target > matrix[x_mid][y_mid]) {
            bool rp = searchMatrixQuad(matrix, x_mid + 1, x_hi, y_lo, y_mid + 1, target);
            bool ln = searchMatrixQuad(matrix, x_lo, x_mid + 1, y_mid + 1, y_hi, target);
            bool rn = searchMatrixQuad(matrix, x_mid + 1, x_hi, y_mid + 1, y_hi, target);
            return (rp || ln || rn);
        } else {
            bool rp = searchMatrixQuad(matrix, x_mid, x_hi, y_lo, y_mid, target);
            bool ln = searchMatrixQuad(matrix, x_lo, x_mid, y_mid, y_hi, target);
            bool lp = searchMatrixQuad(matrix, x_lo, x_mid, y_lo, y_mid, target);
            return (rp || ln || lp);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrixQuad(matrix, 0, matrix.size(), 0, matrix[0].size(), target);
    }
};
