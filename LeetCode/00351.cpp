class Solution {
public:
    // All nCk combinations?
    vector<vector<int>> comb(int N, int K) {
        std::string bitmask(K, 1); // K leading 1's
        bitmask.resize(N, 0); // N-K trailing 0's
        vector<vector<int>> return_comb;
    // print integers and permute bitmask
        do {
            vector<int> single_comb(K);
            int idx = 0;
            for (int i = 0; i < N; ++i) // [0..N-1] integers
            {
                if (bitmask[i]) single_comb[idx++] = i;
            }
            return_comb.push_back(single_comb);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
        return return_comb;
    }
    int valid_permutations(vector<int> &combs, int comb_size) {
        int valid_permutation_cnt = 0;
        do {
            bool valid_comb = true;
            vector<bool> visited(9, false);
            visited[combs[0]] = true;
            for(int i=1; i<comb_size; i++) {
                int sum_prev_curr = combs[i] + combs[i-1];
                if (sum_prev_curr % 2) {
                    visited[combs[i]] = true;
                    continue;
                }
                int col_diff = abs(combs[i] / 3 - combs[i-1] / 3);
                int row_diff = abs(combs[i] % 3 - combs[i-1] % 3);
                if ((col_diff <= 1 && row_diff <= 1) || (col_diff + row_diff) % 2 == 1) {
                    visited[combs[i]] = true;
                    continue;
                }
                if (visited[sum_prev_curr / 2]) {
                    visited[combs[i]] = true;
                    continue;
                }
                valid_comb = false;
                break;
            }
            if (valid_comb) valid_permutation_cnt++;
        } while (next_permutation(combs.begin(), combs.end()));
        return valid_permutation_cnt;
    }
    
    int numberOfPatterns(int m, int n) {
        int valid_patterns = 0;
        for(int i=m; i<=n; i++) {
            vector<vector<int>> nine_i = comb(9, i);
            for(vector<int> c: nine_i) {
                valid_patterns += valid_permutations(c, i);
            }
        }
        return valid_patterns;
    }
};
