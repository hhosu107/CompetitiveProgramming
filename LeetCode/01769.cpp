class Solution {
public:
    vector<int> minOperations(string boxes) {
        // I think the interviewer will ask O(n) solution.
        int one_count = 0;
        for(char b: boxes) {
            one_count += (int)(b - '0');
        }
        int index_left_balls = 0;
        int index_right_balls = one_count;
        vector<int> min_ops(boxes.size(), 0);
        // Compute initial operations at index 0;
        for(int i=1; i<boxes.size(); i++) {
            if (boxes[i] == '1') {
                min_ops[0] += i;
            }
        }
        // Now move the ball by one.
        for(int i=1; i<boxes.size(); i++) {
            if (boxes[i-1] == '1') {
                index_left_balls += 1;
                index_right_balls -= 1;
            }
            min_ops[i] = min_ops[i - 1] + index_left_balls - index_right_balls;
        }
        return min_ops;
    }
};

// Naive solution: O(n^2): compute every distance for every point
// Better solution: O(n). If we increase the index where the previous index had a ball, we will get the incremented movements by one for each left-side ball, where the left side ball's count is increased by 1. Also we will get the decremented movements by one for each right-side ball (since the distance gets), where the right side ball's count is decreased by one. Thus, the difference of the operations is defined by min_ops[index-1] + index_left_balls -
// index_right_balls.
// Initial index_left_balls = 0, index_right_balls = # of 1s.
