class Solution {
public:
  int doubleBinarySearch(vector<int> &nums, int lo, int hi) {
    if (lo >= hi) {
      return nums[2 * lo];
    }
    int mid = (lo + hi) / 2;
    if (nums[2 * mid] != nums[2 * mid + 1]) {
      if (mid == 0 || nums[2 * mid] != nums[2 * mid - 1])
        return nums[2 * mid];
      return doubleBinarySearch(nums, lo, mid);
    } else {
      return doubleBinarySearch(nums, mid + 1, hi);
    }
  }
  int singleNonDuplicate(vector<int> &nums) {
    // Sol) nums' length == 2n - 1.
    // Suppose kth smallest element exists only once.
    // Then, elmt[0] == elmt[1], ..., elmt[2*(k-1)] == elmt[2k-1],
    // elmt[2(k+1)-1] == elmt[2(k+1)], ..., elmt[2(n-1)-1] == elmt[2(n-1)]. Do
    // the binary search on l. If elmt[2*l] != elmt[2*l+1], test elmt[2*l-1] !=
    // elmt[2*l]. If that satisfies, return elmt[2*l], else return the left
    // side. If elmt[2*l] == elmt[2*l+1], do the right side.
    int len = nums.size();
    int unique_len = (len + 1) / 2;
    return doubleBinarySearch(nums, 0, unique_len - 1);
  }
};
