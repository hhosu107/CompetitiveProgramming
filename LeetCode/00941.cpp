class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        bool decreasing_found = false;
        if (arr[0] >= arr[1]) return false;
        for(int i=1; i<arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1] || (arr[i] < arr[i + 1] && decreasing_found)) {
                return false;
            }
            if (arr[i] > arr[i + 1])
                decreasing_found = true;
        }
        return decreasing_found;
    }
};
