class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int h_size = 0, v_size = 0, d_size = 0, a_size = 0;
        int m = mat.size(), n = mat[0].size();
        // height
        for(int i=0; i<m; i++) {
            int consec_i = 0;
            for(int j=0; j<n; j++) {
                if (mat[i][j] == 1) {
                    consec_i += 1;
                } else {
                    h_size = max(h_size, consec_i);
                    consec_i = 0;
                }
            }
            h_size = max(h_size, consec_i);
        }
        // vertical
        for(int i=0; i<n; i++) {
            int consec_i = 0;
            for(int j=0; j<m; j++) {
                if (mat[j][i] == 1) {
                    consec_i += 1;
                } else {
                    h_size = max(h_size, consec_i);
                    consec_i = 0;
                }
            }
            v_size = max(v_size, consec_i);
        }
        // diagonal. constant is: y-x = a.
        for(int a=-(m-1); a<=(n-1); a++) {
            int j_start = max(a, 0);
            int i_start = max(-a, 0);
            int consec_i = 0;
            for(int i=0; i + i_start < m && i + j_start < n; i++) {
                if (mat[i + i_start][i + j_start] == 1) {
                    consec_i += 1;
                } else {
                    d_size = max(d_size, consec_i);
                    consec_i = 0;
                }
            }
            d_size = max(d_size, consec_i);
        }
        // anti diagonal. constant is: y+x = a.
        for(int a=0; a<=(m-1)+(n-1); a++) {
            int j_start = min(n-1, a);
            int i_start = max(0, a - (n - 1));
            int consec_i = 0;
            for(int i=0; j_start - i >= 0 && i + i_start < m; i++) {
                if (mat[i + i_start][j_start - i] == 1) {
                    consec_i += 1;
                } else {
                    a_size = max(a_size, consec_i);
                    consec_i = 0;
                }
            }
            a_size = max(a_size, consec_i);
        }
        return max(max(h_size, v_size), max(a_size, d_size));
    }
};
