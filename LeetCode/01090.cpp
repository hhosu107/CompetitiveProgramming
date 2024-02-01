class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    unordered_map<int, int> label_used;
    using pii = pair<int, int>;
    priority_queue<pii> val_container;
    unordered_map<int, priority_queue<int>> each_label_container;
    for (int i = 0; i < values.size(); i++) {
      if (each_label_container.count(labels[i]) == 0) {
        each_label_container[labels[i]] = priority_queue<int>();
      }
      each_label_container[labels[i]].push(values[i]);
    }
    for (auto it = each_label_container.begin();
         it != each_label_container.end(); it++) {
      int value_top = it->second.top();
      it->second.pop();
      val_container.push({value_top, it->first});
    }
    int wanted_sum = 0;
    int count_wanted = 0;
    while (count_wanted < numWanted && !val_container.empty()) {
      pii value_top = val_container.top();
      val_container.pop();
      if (label_used[value_top.second] >= useLimit) {
        continue;
      }
      wanted_sum += value_top.first;
      label_used[value_top.second] += 1;
      count_wanted += 1;
      if (!each_label_container[value_top.second].empty()) {
        int loc_value_top = each_label_container[value_top.second].top();
        each_label_container[value_top.second].pop();
        val_container.push({loc_value_top, value_top.second});
      }
    }
    return wanted_sum;
  }
};
