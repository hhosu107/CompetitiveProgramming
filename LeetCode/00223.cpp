// Rectangle Area leetcode.com/problems/rectangle-area
#include <algorithm>
class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    if (ax1 > bx1) {
      swap(ax1, bx1);
      swap(ax2, bx2);
      swap(ay1, by1);
      swap(ay2, by2);
    }
    int possibleWidth = min(ax2, bx2) - bx1;
    if (possibleWidth <= 0)
      possibleWidth = 0;
    int possibleHeight = min(ay2, by2) - max(ay1, by1);
    if (possibleHeight <= 0)
      possibleHeight = 0;
    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) -
           possibleWidth * possibleHeight;
  }
};
