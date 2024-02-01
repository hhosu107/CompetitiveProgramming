class Solution {
public:
  vector<int> amountPainted(vector<vector<int>> &paint) {
    int min_start = INT_MAX, max_end = INT_MIN;
    for (const auto &p : paint) {
      min_start = min(min_start, p[0]);
      max_end = max(max_end, p[1]);
    }
    set<int> painting;
    for (int i = min_start; i < max_end; i++)
      painting.insert(i);
    vector<int> amount(paint.size());
    for (int i = 0; i < paint.size(); i++) {
      int erased_count = 0;
      auto it = painting.lower_bound(paint[i][0]);
      while (it != painting.end() && *it < paint[i][1]) {
        it = painting.erase(it);
        erased_count++;
      }
      amount[i] = erased_count;
    }
    return amount;
  }
};

// Sol) Since any cell can be painted at most once,
// first insert every cell between min_start and max_end into the set.
// For each cell in [p[0], p[1]), find lower_bound of the set with p[0] and
// erase elements until the min(end, p(1)) occurs. Then insert the erased count
// to the ith element of the return vector.
