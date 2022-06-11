#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;
class NumArray {
public:
    int size;
    vector<ll> num;
    vector<ll> modifier;
    void update_val(ll idx, ll val) {
        // Update logic was somehow wrong. Fix it.
        while (idx < size) {
            modifier[idx] += val;
            idx += (idx & -idx);
        }
    }
    ll get_sum(int l, int r) {
        l = l - 1;
        ll sum1 = 0;
        while(l > 0) {
            sum1 += modifier[l];
            l -= (l & -l);
        }
        ll sum2 = 0;
        while(r > 0) {
            sum2 += modifier[r];
            r -= (r & -r);
        }
        return sum2 - sum1;
    }
    NumArray(vector<ll>& nums) : num(nums) {
        size = nums.size();
        modifier = vector<ll>(size, 0);
        for(int i=1; i<size; i++) {
            update_val(i, nums[i]);
        }
    }
    void update(ll index, ll val) {
        update_val(index, val - num[index]);
        num[index] = val;
    }
    ll sumRange(ll left, ll right) {
        return get_sum(left, right);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> nums(n + 1);
    for(int i=1; i<=n; i++)
        cin >> nums[i];
    NumArray numArray(nums);
    for(int i=0; i<m + k; i++) {
        ll t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            numArray.update(l, r);
        } else {
            cout << numArray.sumRange(l, r) << '\n';
        }
    }
    return 0;
}
