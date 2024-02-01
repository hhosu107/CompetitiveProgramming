#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    // Sol) Find strict increasing sequence from left to right; right to left;
    // and find any possibility. What we need to track is: from the right side,
    // which is the largest one that is strictly smaller than current element?
    // Answer: use binary search tree (set<int>).
    int len = nums.size();
    if (len < 3)
      return false;
    // vector<int> left_max_idx(len, -1);
    vector<int> left_min_idx(len, -1);
    // vector<int> right_max_idx(len, len);
    vector<int> right_second_max_elmt(len, 1999999999);
    // A vector that saves the second largest variable from the right?
    // left_max_idx[0] = 0;
    left_min_idx[0] = 0;
    set<int> rightside_elements{nums[len - 1]};
    set<int>::iterator it;
    for (int i = 1; i < len; i++) {
      /*
      if (nums[i] > nums[left_max_idx[i-1]]) {
          left_max_idx[i] = i;
      } else left_max_idx[i] = left_max_idx[i-1];
      */
      if (nums[i] < nums[left_min_idx[i - 1]]) {
        left_min_idx[i] = i;
      } else
        left_min_idx[i] = left_min_idx[i - 1];
      rightside_elements.insert(nums[len - 1 - i]);
      it = rightside_elements.lower_bound(
          nums[len - 1 -
               i]); // this finds nums[len - 1 - i]; if it is the begin,
                    // nums[len - 1 - i] is the smallest; otherwise, --it is the
                    // element we wanted to find.
      if (it == rightside_elements.begin())
        continue;
      --it;
      right_second_max_elmt[len - 1 - i] = *it;
      /*
      if (right_second_max_idx[len - i] == len) {
          if (nums[len - 1 - i] > nums[len - 1]) {
              right_second_max_idx[len - i - 1] = len - 1;
          }
      }
      if (nums[len - 1 - i] > nums[right_max_idx[len - i]]) {
          if (right_second_max_idx[len - i] < len) {
              right_second_max_idx[len - 1 - i] = right_max_idx[len - i];
          }
          right_max_idx[len - 1 - i] = len - 1 - i;
      } else {
          right_second_max_idx[len - 1 - i] = right_second_max_idx[len - i];
          right_max_idx[len - 1 - i] = right_max_idx[len - i];
      }
      */
    }
    for (int i = 1; i < len - 1; i++) {
      if (nums[i] > nums[left_min_idx[i]] &&
          nums[i] > right_second_max_elmt[i] &&
          right_second_max_elmt[i] > nums[left_min_idx[i]]) {
        return true;
      }
    }
    return false;
  }
};
