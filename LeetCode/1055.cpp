class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> possible_pool;
        for (char c: source)
            possible_pool.insert(c);
        for (char t: target) {
            if (possible_pool.find(t) == possible_pool.end())
                return -1;
        }
        // Greedy.
        int source_len = source.length();
        int source_idx = 0;
        int source_usage = 1;
        int target_window = 0;
        while (target_window < target.length()) {
            if (source_idx >= source_len) {
                source_usage += 1;
                source_idx = 0;
            }
            if (source[source_idx] == target[target_window]) {
                target_window += 1;
            }
            source_idx += 1;
        }
        return source_usage;
    }
};
