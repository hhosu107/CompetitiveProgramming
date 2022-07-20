class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // Sol) Same as LCS.
        vector<vector<int>> lcs(nums1.size() + 1, vector<int>(nums2.size() + 1));
        for(int i=1; i<=nums1.size(); i++) {
            for(int j=1; j<=nums2.size(); j++) {
                if (nums1[i-1] == nums2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
                else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
        return lcs[nums1.size()][nums2.size()];
    }
};

// Line crossing == longest common subsequence 규칙에 위배.
