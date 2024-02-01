class Solution {
public:
  vector<int> sumZero(int n) {
    int delta = n / 2;
    vector<int> arr(n);
    for (int i = -delta; i <= delta; i++) {
      if (i == delta && n % 2 == 0)
        break;
      if (i >= 0 && n % 2 == 0) {
        arr[i + delta] = i + 1;
      } else
        arr[i + delta] = i;
    }
    return arr;
  }
};
