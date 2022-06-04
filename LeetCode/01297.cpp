/* Sol) Do not care about maxSize. Only focus on minSize.
This is because:
if the longer pattern occurs most frequently,
it indicates that every subpattern in that longer pattern occurs at least that much.
*/
/* I want to use hashmap.
map<string, int> that contains the number of occurrences in the string.
*/
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        vector<int> char_occ(26);
        string pat = "";
        int uniq_occ = 0;
        map<string, int> occs;
        for (int i=0; i<s.length(); i++) {
            pat += s[i];
            char_occ[s[i] - 'a'] += 1;
            if (char_occ[s[i] - 'a'] == 1) 
                uniq_occ += 1;
            if (i >= minSize) {
                char_occ[s[i-minSize] - 'a'] -= 1;
                if (char_occ[s[i-minSize] - 'a'] == 0)
                    uniq_occ -= 1;
                pat = pat.substr(1);
                cout << pat << endl;
            }
            if (i >= minSize - 1 && uniq_occ <= maxLetters) {
                occs[pat] += 1;
            }
        }
        int max_occ = 0;
        for(auto it=occs.begin(); it != occs.end(); it++) {
            max_occ = max(max_occ, it->second);
        }
        return max_occ;
    }
};
