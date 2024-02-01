class Solution {
public:
  bool canCross(vector<int> &stones) {
    map<int, set<int>> stone_arrival_steps; // key: location of stone; value:
                                            // steps that arrived on key
    for (int i = 0; i < stones.size(); i++) {
      stone_arrival_steps[stones[i]] = set<int>();
    }
    stone_arrival_steps[0].insert(0);
    for (int i = 0; i < stones.size(); i++) {
      for (int k : stone_arrival_steps[stones[i]]) {
        for (int step = k - 1; step <= k + 1; step++) {
          if (step > 0 && stone_arrival_steps.count(stones[i] + step) != 0) {
            stone_arrival_steps[stones[i] + step].insert(step);
          }
        }
      }
    }
    return stone_arrival_steps[stones[stones.size() - 1]].size() > 0;
  }
};

// 각 돌은 reachable했던 직전 돌들로부터의 step을 저장해 두고 있다.
// 자기 차례가 되면, 그 step들을 traverse하고, 그 step들 +1, 0, -1 위치에 다른
// 돌이 있다면, 그 돌한테 해당 step을 저장시킨다.
// 마지막으로 마지막 돌이 step을 가지고 있다면 ok.
