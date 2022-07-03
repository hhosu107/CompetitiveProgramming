class Solution {
public:
    map<string, int> mem = map<string, int>();
    int dfs(int x, int y) {
        string key = to_string(x) + "," + to_string(y);
        if (mem.find(key) != mem.end()) {
            return mem[key];
        }
        if (x + y == 0) return 0; // exact position
        else if (x + y == 2) return 2; // distance between curr pos to the destination == 2
        else {
            int ret = min(dfs(abs(x - 1), abs(y - 2)), dfs(abs(x - 2), abs(y - 1))) + 1;
            mem[key] = ret;
            return ret;
        }
    }
    int minKnightMoves(int x, int y) {
        return dfs(abs(x), abs(y));
    }
};
