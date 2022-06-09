class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> char_map;
        map<char, char> rev_char_map;
        for(int i=0; i<s.length(); i++) {
            char sc = s[i], tc = t[i];
            if (char_map.find(sc) == char_map.end() && rev_char_map.find(tc) != rev_char_map.end()) {
                return false;
            } else if (char_map.find(sc) != char_map.end() && rev_char_map.find(tc) == rev_char_map.end()) {
                return false;
            } else if (char_map.find(sc) != char_map.end() && rev_char_map.find(tc) != rev_char_map.end() && (char_map[sc] != tc || rev_char_map[tc] != sc)) {
                return false;
            } else {
                char_map[sc] = tc;
                rev_char_map[tc] = sc;
            }
        }
        return true;
    }
};
