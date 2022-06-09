using psi = pair<string, int>;
class Solution {
public:
    psi decodeStringInBracket(string &s, int start_idx, int len) {
        string ret = "";
        int idx = start_idx;
        while (idx < len) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                int rep = 0;
                int next_idx = idx;
                while(s[next_idx] != '[') {
                    rep = 10 * rep + (int)(s[next_idx] - '0');
                    next_idx += 1;
                }
                psi internal_ret = decodeStringInBracket(s, next_idx + 1, len);
                for (int i=0; i<rep; i++) {
                    ret += internal_ret.first;
                }
                idx = internal_ret.second + 1;
            } else if (s[idx] == ']') {
                return make_pair(ret, idx);
            } else {
                ret += s[idx];
                idx += 1;
            }
        }
        return make_pair(ret, len);
    }
    
    string decodeString(string s) {
        s = "1[" + s + "]";
        psi ret = decodeStringInBracket(s, 0, s.length());
        return ret.first;
    }
};
