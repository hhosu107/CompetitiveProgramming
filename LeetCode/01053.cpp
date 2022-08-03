class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if (arr.size() == 1) return arr;
        int len = arr.size();
        for(int i=len - 1; i>=1; i--) {
            if (arr[i-1] > arr[i]) {
                // Find largest element between arr[i:len] that is smaller than arr[i-1].
                auto it = lower_bound(arr.begin() + i, arr.end(), arr[i-1]); // that finds the smallest/leftmost element that is larger than or equal to arr[i-1].
                it--; // largest element that is smaller than arr[i-1].
                // if there are some more elements with same value as 'it', find that smallest one.
                // Actually (in the sense of the time complexity), doing one more lower_bound(arr.begin(), it + 1, *it) reduces the time complexity. Practically the below one is more efficient.)
                int val = *it;
                do {
                    if (it == arr.begin()) break;
                    it--;
                    if (*it != val) {
                        it++;
                        break;
                    }
                } while(1);
                size_t dist = distance(arr.begin(), it);
                swap(arr[i-1], arr[dist]);
                // reverse(arr.begin() + i, arr.end());
                return arr;
            }
        }
        return arr;
    }
};
// naive solution: try all possible n^2 comparisons and leave the best.
