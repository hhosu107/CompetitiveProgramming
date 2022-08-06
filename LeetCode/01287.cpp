class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int success = arr.size() / 4 + 1;
        int curr_int = arr[0];
        int curr_cnt = 1;
        if (curr_cnt >= success) return curr_int;
        for(int i=1; i<arr.size(); i++) {
            if (curr_int == arr[i]) {
                curr_cnt += 1;
                if (curr_cnt >= success)
                    return curr_int;
            } else {
                curr_int = arr[i];
                curr_cnt = 1;
            }
        }
        return -1;
    }
};
