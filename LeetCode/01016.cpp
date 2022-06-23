class Solution {
public:
    bool queryString(string s, int n) {
        int bin_size = s.length();
        set<int> bin_rep;
        for(int i=1; i<=min(bin_size, 30); i++) {
            int init_rep = 0;
            for(int j=0; j<i; j++) {
                init_rep = 2 * init_rep + (int)(s[j] - '0');
            }
            bin_rep.insert(init_rep);
            for(int j=1; j<=bin_size - i; j++) {
                int topmost_bit = (init_rep >> (i - 1)) & 1;
                init_rep -= topmost_bit * (1 << (i - 1));
                init_rep = 2 * init_rep + (int)(s[i + j - 1] - '0');
                bin_rep.insert(init_rep);
            }
        }
        for(int i=1; i<=n; i++) {
            if (bin_rep.find(i) == bin_rep.end()) {
                return false;
            }
        }
        return true;
    }
};
