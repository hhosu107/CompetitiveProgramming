/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
/* Solution: we will use binary search to make this algorithm work within log n
 * time complexity.
 */
class Solution {
public:
  int guessNumber(int n) {
    long long int l = 1, r = n;
    do {
      long long int mid = (l + r) / 2;
      int ret = guess((int)(mid));
      if (ret == 0) {
        return (int)(mid);
      } else if (ret > 0) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    } while (l < r);
    return (int)(l);
  }
};
