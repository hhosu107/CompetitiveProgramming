class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Sol) Compute the maximum size of square starting from [i][j]. Then sum all of them.
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        for(int i=m-1; i>=0; i--)
            res += matrix[n-1][i]; 
        for(int i=n-1-1; i>=0; i--)
            res += matrix[i][m-1];
        for(int k = 1; k<=min(n-1, m-1); k++) {
            for(int i=n-1-k; i>=0; i--) {
                if (matrix[i][m-1-k] == 1) {
                    int cell = min({matrix[i+1][m-k], matrix[i+1][m-1-k], matrix[i][m-k]}) + 1;
                    res += cell;
                    matrix[i][m-k-1] = cell;
                }
            }
            for(int i=m-2-k; i>=0; i--) {
                if (matrix[n-1-k][i] == 1) {
                    int cell = min({matrix[n-k][i+1], matrix[n-k][i], matrix[n-1-k][i+1]}) + 1;
                    res += cell;
                    matrix[n-k-1][i] = cell;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        return res;
    }
};

// 문제: cache friendly하지 않다. 그냥 row만 잡고 쭉 reverse하는 게 더 낫다.
