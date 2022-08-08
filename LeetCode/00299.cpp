class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> guess_remaining, secret_remaining;
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
};
// This generates number baseball strike/balls.
// Reveresely, how to guess secret from strike/balls?
// This one would be the key of wordle game.
