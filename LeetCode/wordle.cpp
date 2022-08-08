/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     pair<vector<int>, vector<int>> guess(string word); // strike, ball
 * };
 */
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> guess_remaining, secret_remaining;
        int matched_chars = 0;
        int rearrangable_chars = 0;
        for(int i=0; i<secret.length(); i++) {
            if (secret[i] == guess[i]) {
                matched_chars += 1;
            } else {
                guess_remaining[guess[i]] += 1;
                secret_remaining[secret[i]] += 1;
            }
        }
        for (int i=0; i<=9; i++) {
            char key = (char)(i + '0');
            int mismatched_keys = min(guess_remaining[key], secret_remaining[key]);
            rearrangable_chars += mismatched_keys;
        }
        string hint_str = "";
        hint_str += to_string(matched_chars);
        hint_str += 'A';
        hint_str += to_string(rearrangable_chars);
        hint_str += 'B';
        return hint_str;
    }
    vector<string> candidates;
    int remaining_words;
    unordered_map<string, unordered_map<string, int>> internal_diffs;
    int internal_guess(string &prev_candidate, string &candidate) {
        int equals = 0;
        for (int i=0; i<prev_candidate.length(); i++) {
            if (prev_candidate[i] == candidate[i]) equals++;
        }
        return equals;
    }
    
    void erase_impossibilities(string &guessed, pair<vector<int>, vector<int>> &res) {
        int curr_word_idx = 0;
        unordered_set<char> possible_chars;
        for(int i=0; i<res.second.size(); i++) {
            possible_chars.insert(guessed[res.second[i]]);
        }
        // candidates: [..., last_candidate, ...] candidates[remaining_words] = last_candidate
        while(curr_word_idx < remaining_words) {
            int internal_score = internal_diffs[guessed][candidates[curr_word_idx]];
            if (internal_score != res.first.size()) {
                remaining_words -= 1;
                swap(candidates[curr_word_idx], candidates[remaining_words]);
                candidates.pop_back();
                continue;
            }
            bool invalid_pos = false;
            for(int i=0; i<res.first.size(); i++) {
                if (guessed[res.first[i]] > candidates[curr_word_idx][res.first[i]]) {
                    invalid_pos = true;
                    break;
                }
            }
            if (invalid_pos) {
                remaining_words -= 1;
                swap(candidates[curr_word_idx], candidates[remaining_words]);
                candidates.pop_back();
                continue;
            }
            unordered_set<char> curr_word_possible_chars;
            for(char c: candidates[curr_word_idx]) {
                if (possible_chars.find(c) != possible_chars.end()) {
                    curr_word_possible_chars.insert(c);
                }
            }
            if (curr_word_possible_chars.size() < possible_chars.size()) {
                remaining_words -= 1;
                swap(candidates[curr_word_idx], candidates[remaining_words]);
                candidates.pop_back();
                continue;
            }
            curr_word_idx += 1;
        }
    }
    
    void construct_internal_diffs() {
        for(int i=0; i<candidates.size() - 1; i++) {
            for(int j=0; j<candidates.size(); j++) {
                int between_guess = internal_guess(candidates[i], candidates[j]);
                internal_diffs[candidates[i]][candidates[j]] = between_guess;
                internal_diffs[candidates[j]][candidates[i]] = between_guess;
            }
        }
    }
    
    string next_candidate() {
        if (candidates.size() == 1) return candidates[0];
        int max_possible_reduction = 0;
        string next_cand = "";
        int next_candidate_idx = 0;
        for(int i=0; i<remaining_words; i++) {
            unordered_map<int, int> guess_count;
            int max_occurrence = -1;
            int max_occurrence_count = 0;
            for(int j=0; j<remaining_words; j++) {
                if (i == j) continue;
                int curr_diff = internal_diffs[candidates[i]][candidates[j]];
                guess_count[curr_diff]++;
                if (max_occurrence_count < guess_count[curr_diff]) {
                    max_occurrence = curr_diff;
                    max_occurrence_count = guess_count[curr_diff];
                }
            }
            int reducible_count = remaining_words - max_occurrence_count;
            if (max_possible_reduction < reducible_count) {
                max_possible_reduction = reducible_count;
                next_cand = candidates[i];
                next_candidate_idx = i;
            }
        }
        remaining_words -= 1;
        swap(candidates[next_candidate_idx], candidates[remaining_words]);
        candidates.pop_back();
        return next_cand;
    }
    
    void findSecretWord(vector<string>& words, Master& master) {
        if (words.size() == 1) {
            master.guess(words[0]);
            return;
        }
        candidates = vector<string>(words);
        remaining_words = candidates.size();
        construct_internal_diffs();
        string next_word = next_candidate();
        pair<vector<int>, vector<int>> guessed_result = master.guess(next_word);
        while(guessed_result.first.size() != 6) {
            erase_impossibilities(next_word, guessed_result); // erase impossible ones
            next_word = next_candidate();
            guessed_result = master.guess(next_word);
        }
    }
};
