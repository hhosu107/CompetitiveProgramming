class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
        int val;
        for(int i=0; i<arr1.size(); i++) {
            val = arr1[i] + arr2[i] + i;
            max1 = max(max1, val);
            min1 = min(min1, val);
            val = arr1[i] - arr2[i] + i;
            max2 = max(max2, val);
            min2 = min(min2, val);
            val = -arr1[i] + arr2[i] + i;
            max3 = max(max3, val);
            min3 = min(min3, val);
            val = -arr1[i] - arr2[i] + i;
            max4 = max(max4, val);
            min4 = min(min4, val);
        }
        return max({max1 - min1, max2 - min2, max3 - min3, max4 - min4});
    }
};
