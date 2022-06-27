class Solution {
public:
    
    
    bool canConvert(string str1, string str2) {
        // 1. Initial state에서 같은 character가 target의 서로 다른 character로 mapping되어야 하는 상황이 있다면 false.
        // 2. Initial state에서 어떤 character가 target의 character로 mapping될 때, target의 character가 이미 initial state에 나타나있는 상황이라면 chain.
             // chain의 마지막에, initial state에는 없는 character여야 한다.
             // 만약 chain이 loop를 만들고 있다면, swapping rule에 의해, 어떤 character를 temporary state로 둬야 하는데, 이 때 이 character는 initial state 및 target 어디에도 없는 character여야 한다.
             // 그런 character가 존재하지 않는다면 false.
        // 1번 감지는 쉽고, 2번의 경우, cycle detection을 통해, cycle이 있다면 key + value 통틀어 최대 25개의 english character만 존재해야 하며 (단 self cycle 26개인 경우 예외), 아니면 26개 다 있어도 된다.
        map<char, char> init_to_target;
        map<char, int> mapped_count;
        set<char> used_chars;
        set<char> used_chars_in_target;
        for(int i=0; i<str2.length(); i++) {
            used_chars.insert(str1[i]);
            used_chars.insert(str2[i]);
            used_chars_in_target.insert(str2[i]);
            if (init_to_target.find(str1[i]) != init_to_target.end() && init_to_target[str1[i]] != str2[i]) {
                return false;
            }
            if (init_to_target.find(str1[i]) == init_to_target.end()) {
                init_to_target[str1[i]] = str2[i];
                if (mapped_count.count(str1[i]) == 0) {
                    mapped_count[str1[i]] = 0;
                }
                if (mapped_count.count(str2[i]) == 0) {
                    mapped_count[str2[i]] = 0;
                }
                mapped_count[str2[i]] += 1;
            }
        }
        map<char, char> init_to_target_excluding_self_cycle;
        int self_cycle_cnt = 0;
        for(auto [k, v]: init_to_target) {
            if (k == v) {
                mapped_count[k]--;
                self_cycle_cnt++;
            } else {
                init_to_target_excluding_self_cycle[k] = v;
            }
        }
        int used_pool_size = used_chars.size();
        int non_cycle_chars = 0;
        queue<char> outermost_chars; // cycle detection
        for(auto it=mapped_count.begin(); it!=mapped_count.end(); it++) {
            if (it->second == 0 && init_to_target_excluding_self_cycle.find(it->first) != init_to_target_excluding_self_cycle.end())
                outermost_chars.push(it->first);
        }
        while(!outermost_chars.empty()) {
            char curr = outermost_chars.front();
            outermost_chars.pop();
            mapped_count[init_to_target[curr]] -= 1;
            if (mapped_count[init_to_target[curr]] == 0) {
                outermost_chars.push(init_to_target[curr]);
            }
            non_cycle_chars += 1;
        }
        // if (non_cycle_chars < used_pool_size)
        //    return used_pool_size <= 25;
        // return true;
        return (used_pool_size <= 25) || non_cycle_chars > 0 || (self_cycle_cnt == used_chars_in_target.size());
        // each condition matches: at most 25 different characters in the str1 + str2, at most 25
        // different characters in the str2, identicality
    }
};
