class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    int consecutive_max = neededTime[0];
    int consecutive_sum = neededTime[0];
    int consecutive_start = 0;
    char curr_color = colors[0];
    int cost = 0;
    for (int i = 1; i < neededTime.size(); i++) {
      if (curr_color != colors[i]) {
        cost += consecutive_sum - consecutive_max;
        consecutive_sum = neededTime[i];
        consecutive_max = neededTime[i];
        consecutive_start = i;
        curr_color = colors[i];
      } else {
        consecutive_sum += neededTime[i];
        consecutive_max = max(consecutive_max, neededTime[i]);
      }
    }
    cost += consecutive_sum - consecutive_max;
    return cost;
  }
};
