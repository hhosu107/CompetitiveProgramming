class NumArray {
public:
  int size;
  vector<int> num;
  vector<int> modifier;
  void update_val(int idx, int val) {
    while (idx < size) {
      modifier[idx] += val;
      idx += (idx & -idx);
    }
  }
  int get_sum(int l, int r) {
    l = l - 1;
    int sum1 = 0;
    while (l > 0) {
      sum1 += modifier[l];
      l -= (l & -l);
    }
    int sum2 = 0;
    while (r > 0) {
      sum2 += modifier[r];
      r -= (r & -r);
    }
    return sum2 - sum1;
  }
  NumArray(vector<int> &nums) {
    num = nums;
    size = nums.size() + 1;
    modifier = vector<int>(size, 0);
    for (int i = 0; i < size - 1; i++) {
      update_val(i + 1, nums[i]);
    }
  }

  void update(int index, int val) {
    update_val(index + 1, val - num[index]);
    num[index] = val;
  }

  int sumRange(int left, int right) { return get_sum(left + 1, right + 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
