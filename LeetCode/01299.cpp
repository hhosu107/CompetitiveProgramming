class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    int max_right = -1;
    vector<int> replaced_elements(arr.size());
    replaced_elements[arr.size() - 1] = -1;
    if (arr.size() == 1)
      return replaced_elements;
    for (int j = arr.size() - 2; j >= 0; j--) {
      max_right = max(max_right, arr[j + 1]);
      replaced_elements[j] = max_right;
    }
    return replaced_elements;
  }
};
