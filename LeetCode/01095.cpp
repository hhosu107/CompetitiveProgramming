/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
  int binaryPeak(MountainArray &arr, int lo, int hi) {
    if (lo + 1 >= hi) {
      int lower = arr.get(lo);
      int higher = arr.get(hi);
      if (lower > higher)
        return lo;
      else
        return hi;
    }
    int mid = (lo + hi) / 2;
    int mid_val = arr.get(mid);
    int mid_next = arr.get(mid + 1);
    if (mid_val > mid_next)
      return binaryPeak(arr, lo, mid);
    else
      return binaryPeak(arr, mid, hi);
  }
  int targetAscending(MountainArray &arr, int lo, int hi, int target,
                      int arr_len) {
    if (lo + 1 >= hi) {
      int lower = arr.get(lo);
      int higher = ((hi < 0 || hi >= arr_len) ? 1000000001 : arr.get(hi));
      if (lower == target)
        return lo;
      if (higher == target)
        return hi;
      return -1;
    }
    int mid = (lo + hi) / 2;
    int mid_val = arr.get(mid);
    if (mid_val == target)
      return mid;
    else if (mid_val > target)
      return targetAscending(arr, lo, mid, target, arr_len);
    else
      return targetAscending(arr, mid + 1, hi, target, arr_len);
  }
  int targetDescending(MountainArray &arr, int lo, int hi, int target,
                       int arr_len) {
    if (lo + 1 >= hi) {
      int lower = (lo >= arr_len ? 1000000001 : arr.get(lo));
      int higher = (hi >= arr_len ? 1000000001 : arr.get(hi));
      if (lower == target)
        return lo;
      if (higher == target)
        return hi;
      return -1;
    }
    int mid = (lo + hi) / 2;
    int mid_val = arr.get(mid);
    if (mid_val == target)
      return mid;
    else if (mid_val < target)
      return targetDescending(arr, lo, mid, target, arr_len);
    else
      return targetDescending(arr, mid + 1, hi, target, arr_len);
  }
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int arr_len = mountainArr.length();
    int peakIdx = binaryPeak(mountainArr, 0, arr_len);
    int left_idx =
        targetAscending(mountainArr, 0, peakIdx + 1, target, arr_len);
    if (left_idx != -1)
      return left_idx;
    int right_idx =
        targetDescending(mountainArr, peakIdx, arr_len, target, arr_len);
    if (right_idx != -1)
      return right_idx;
    return -1;
  }
};
