// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// Care about boundary case that makes an overflow.
using ll = long long;
class Solution {
public:
    ll firstBadVersionBin(ll l, ll r) {
        if (l + 1 >= r) {
            bool ret = isBadVersion(l + 1);
            if (!ret) return -1;
            else return l;
        }
        ll mid = (l + r) / 2;
        if (isBadVersion(mid + 1)) {
            ll ret = firstBadVersionBin(l, mid);
            if (ret >= 0) {
                return ret;
            } else return mid;
        } else {
            return firstBadVersionBin(mid + 1, r);
        }
    }
    int firstBadVersion(int n) {
        ll l = 0, r = n; // If n == 2^31 - 1, l + r causes an overflow.
        ll ret = firstBadVersionBin(l, r);
        if (ret >= 0) {
            return ret + 1;
        }
        return n;
    }
};
/* Typical binary search:
 * Make the term as [l, r); check (l + 1 >= r) for the terminal case.
 * If the search aims to find the exact value, split into [l, mid) and [mid + 1,
 * r). Otherwise, split into [l, mid) and [mid, r).
 */
