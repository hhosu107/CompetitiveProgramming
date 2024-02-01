class Solution {
public:
  string frequencySort(string s) {
    // Sol) Do the bucket sort and print out the biggest bucket first.
    using pic = pair<int, char>;
    auto pic_comp = [](const pic &a, const pic &b) {
      if (a.first != b.first)
        return a.first < b.first;
      return a.second < b.second;
    };
    map<char, int> freq;
    for (char c : s)
      freq[c] += 1;
    priority_queue<pic, vector<pic>, decltype(pic_comp)> pq(pic_comp);
    for (const auto &[k, v] : freq)
      pq.push({v, k});
    string res = "";
    while (!pq.empty()) {
      auto [v, k] = pq.top();
      pq.pop();
      for (int i = 0; i < v; i++)
        res += k;
    }
    return res;
  }
};
