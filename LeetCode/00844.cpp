class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_revidx = s.length() - 1;
        int t_revidx = t.length() - 1;
        int s_backspaces = 0, t_backspaces = 0;
        bool same_string = true;
        while(s_revidx >= 0 || t_revidx >= 0) {
            if (s_revidx >= 0 && s[s_revidx] == '#') {
                s_backspaces += 1;
                s_revidx -= 1;
                while(s_revidx >= 0 && s_backspaces >= 0) {
                    if (s_backspaces == 0 && s[s_revidx] != '#') break;
                    if (s[s_revidx] == '#') s_backspaces += 1;
                    else s_backspaces -= 1;
                    s_revidx -= 1;
                }
            }
            bool valid_sidx = (s_revidx >= 0);
            if (t_revidx >= 0 && t[t_revidx] == '#') {
                t_backspaces += 1;
                t_revidx -= 1;
                while(t_revidx >= 0 && t_backspaces >= 0) {
                    if (t_backspaces == 0 && t[t_revidx] != '#') break;
                    if (t[t_revidx] == '#') t_backspaces += 1;
                    else t_backspaces -= 1;
                    t_revidx -= 1;
                }
            }
            bool valid_tidx = (t_revidx >= 0);
            if (!valid_sidx && !valid_tidx) break;
            else if (!valid_sidx && valid_tidx) return false;
            else if (valid_sidx && !valid_tidx) return false;
            if (s[s_revidx] != t[t_revidx]) return false;
            else {
                s_revidx -= 1;
                t_revidx -= 1;
            }
        }
        return true;
    }
};
