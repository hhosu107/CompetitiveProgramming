class Solution {
public:
  int binaryPeak(vector<int> &arr, int lo, int hi) {
    if (lo + 1 >= hi) {
      if (arr[lo] > arr[hi])
        return lo;
      else
        return hi;
    }
    int mid = (lo + hi) / 2;
    if (arr[mid] > arr[mid + 1])
      return binaryPeak(arr, lo, mid);
    else
      return binaryPeak(arr, mid, hi);
  }
  int peakIndexInMountainArray(vector<int> &arr) {
    return binaryPeak(arr, 0, arr.size());
  }
};
