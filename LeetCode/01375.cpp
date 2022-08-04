class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        // sol) At time n, if the max[flips[1:n]] == n, then it is prefix aligned (since this is the permutation)
        int flip_max = 0;
        int prefix_aligned = 0;
        for(int i=1; i<=flips.size(); i++) {
            flip_max = max(flip_max, flips[i-1]);
            if (flip_max == i)
                prefix_aligned += 1;
        }
        return prefix_aligned;
    }
};
