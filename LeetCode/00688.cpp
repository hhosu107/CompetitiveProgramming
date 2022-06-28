class Solution {
public:
    unordered_map<string, double> move_prob; // key = [row, col, how_many_moves_left], prob = probability that alives on the board after movements
    int dir[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    double find(int n, int moves, int r, int c) {
        if (r < 0 || r >= n || c < 0 || c >= n) return 0.0;
        if (moves == 0) return 1.0;
        string mem_key = to_string(r) + "_" + to_string(c) + "_" + to_string(moves);
        if (move_prob.find(mem_key) != move_prob.end()) return move_prob[mem_key];
        double sum_prob = 0.0;
        for (int i=0; i<8; i++) {
            // DP equation of previous state = average of next states.
            sum_prob += 0.125 * find(n, moves - 1, dir[i][0] + r, dir[i][1] + c);
        }
        move_prob[mem_key] = sum_prob;
        return sum_prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        return find(n, k, row, column);
    }
};
// Probability: If there are no limitations to take any next moves, just compute
// the average of next states from the current states with DP, and return the
// initial state's probability.
