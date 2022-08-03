class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> chars; // this one always contains unique character.
        unordered_set<char> seen_chars; // this one indicates what characters are in the stack.
        unordered_map<char, int> last_occ; // The character we want to eliminate (to make the entire string smaller) from the stack cannot be eliminated since current index is bigger than stack to character's last occurrence.
        for(int i=0; i<s.length(); i++)
            last_occ[s[i]] = i;
        for(int i=0; i<s.length(); i++) {
            if (seen_chars.find(s[i]) == seen_chars.end()) {
                while(!chars.empty() && s[i] < chars.top() && i < last_occ[chars.top()]) {
                    seen_chars.erase(chars.top());
                    chars.pop();
                }
                seen_chars.insert(s[i]);
                chars.push(s[i]);
            }
        }
        string reversed_occ = "";
        while(!chars.empty()) {
            reversed_occ += chars.top();
            chars.pop();
        }
        reverse(reversed_occ.begin(), reversed_occ.end());
        return reversed_occ;
    }
};
