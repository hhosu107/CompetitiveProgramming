class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        priority_queue<int> heaviest_stones;
        for(int s: stones)
            heaviest_stones.push(s);
        while(heaviest_stones.size() > 1) {
            int first_heavy = heaviest_stones.top();
            heaviest_stones.pop();
            int second_heavy = heaviest_stones.top();
            heaviest_stones.pop();
            if (first_heavy - second_heavy > 0) {
                heaviest_stones.push(first_heavy - second_heavy);
            }
        }
        if (heaviest_stones.size() == 1) return heaviest_stones.top();
        return 0;
    }
};
