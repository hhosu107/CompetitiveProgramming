class Solution {
public:
    string modifyString(string s) {
        if (s.length() == 1 && s[0] == '?') return "a";
        else if (s.length() == 1) return s;
        string modified = "";
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '?') {
                if (i == 0) {
                    s[i] = (s[i + 1] == 'a' ? 'b' : 'a');
                } else if (i == s.length() - 1) {
                    s[i] = (s[i-1] == 'a' ? 'b' : 'a');
                } else {
                    set<char> near{s[i-1], s[i + 1]};
                    if (near.find('a') == near.end()) s[i] = 'a';
                    else if (near.find('b') == near.end()) s[i] = 'b';
                    else s[i] = 'c';
                }
            }
        }
        return s;
    }
};
