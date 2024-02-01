#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                 vector<int> &nums4) {
  int len = nums1.size();
  vector<int> nums12 = vector<int>(len * len, 0);
  vector<int> nums34 = vector<int>(len * len, 0);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      nums12[i * len + j] = (long long int)(nums1[i] + nums2[j]);
      nums34[i * len + j] = (long long int)(nums3[i] + nums4[j]);
    }
  }
  sort(nums12.begin(), nums12.end());
  sort(nums34.begin(), nums34.end());
  for (int x : nums12) {
    cout << x << " ";
  }
  cout << endl;
  for (int x : nums34) {
    cout << x << " ";
  }
  cout << endl;
  int left12 = 0;
  int right34 = len * len - 1;
  int ans = 0;
  while (left12 < len * len && right34 >= 0) {
    if (nums12[left12] + nums34[right34] == 0) {
      int same12 = 1, same34 = 1;
      for (int i = left12 + 1; i < len * len; i++) {
        if (nums12[left12] != nums12[i])
          break;
        same12++;
      }
      for (int j = right34 - 1; j >= 0; j--) {
        if (nums34[right34] != nums34[j])
          break;
        same34++;
      }
      ans += same12 * same34;
      left12 += same12;
      right34 -= same34;
    } else if (nums12[left12] + nums34[right34] < 0) {
      left12++;
    } else
      right34--;
  }
  return ans;
}

int main() {
  vector<int> a1 = vector<int>(2), a2 = vector<int>(2), a3 = vector<int>(2),
              a4 = vector<int>(2);
  int n = 2;
  for (int i = 0; i < n; i++)
    cin >> a1[i];
  for (int i = 0; i < n; i++)
    cin >> a2[i];
  for (int i = 0; i < n; i++)
    cin >> a3[i];
  for (int i = 0; i < n; i++)
    cin >> a4[i];
  cout << fourSumCount(a1, a2, a3, a4) << endl;
  return 0;
}
