class Solution {
public:
    void all_words(vector<vector<string>> &idx_strings, int curr_idx, int patterns_size, string curr_str, vector<string> &answer) {
        if (curr_idx == patterns_size) {
            answer.push_back(curr_str);
            return;
        }
        for(string str : idx_strings[curr_idx]) {
            all_words(idx_strings, curr_idx + 1, patterns_size, curr_str + str, answer);
        }
    }
    
    vector<string> expand(string s) {
        // Sol) For each index, save into a vector of words.
        int word_chunk_idx = 0;
        int char_idx = 0;
        string found_pattern = "";
        vector<vector<string>> idx_strings;
        while (char_idx < s.length()) {
            if (s[char_idx] == '{') { // Run nested one
                char_idx++;
                if (found_pattern != "") {
                    idx_strings.push_back(vector<string>{found_pattern});
                    found_pattern = "";
                }
                vector<string> sub_patterns;
                while(s[char_idx] != '}') {
                    if (s[char_idx] == ',') {
                        if (found_pattern != "") {
                            sub_patterns.push_back(found_pattern);
                            found_pattern = "";
                        }
                    } else {
                        found_pattern += s[char_idx];
                    }
                    char_idx++;
                }
                if (found_pattern != "") {
                    sub_patterns.push_back(found_pattern);
                    found_pattern = "";
                }
                sort(sub_patterns.begin(), sub_patterns.end());
                idx_strings.push_back(sub_patterns);
                char_idx++;
            } else {
                found_pattern += s[char_idx];
                char_idx++;
            }
        }
        if (found_pattern != "") {
            idx_strings.push_back(vector<string>{found_pattern});
        }
        int patterns_len = idx_strings.size();
        vector<string> answer;
        all_words(idx_strings, 0, patterns_len, "", answer);
        return answer;
    }
};
