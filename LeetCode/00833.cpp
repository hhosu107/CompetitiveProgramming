class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        using pis = pair<int, string>;
        auto comp = [](const pis &a, const pis &b) {
            return (a.first < b.first) || (a.first == b.first && a.second < b.second);
        };
        vector<pis> si(indices.size()), ti(indices.size());
        for(int i=0; i<indices.size(); i++) {
            si[i] = make_pair(indices[i], sources[i]);
            ti[i] = make_pair(indices[i], targets[i]);
        }
        sort(si.begin(), si.end(), comp);
        sort(ti.begin(), ti.end(), comp);
        vector<pis> substitutions(indices.size());
        for(int i=0; i<indices.size(); i++) {
            if (s.substr(si[i].first, si[i].second.length()) == si[i].second) {
                substitutions[i] = make_pair(si[i].first, ti[i].second);
            } else substitutions[i] = make_pair(si[i].first, s.substr(si[i].first, si[i].second.length()));
        }
        string ret = "";
        int curr_s_idx = 0;
        int curr_sub_idx = 0;
        while(curr_s_idx < s.length()) {
            if (curr_sub_idx < indices.size() && substitutions[curr_sub_idx].first == curr_s_idx) {
                ret += substitutions[curr_sub_idx].second;
                curr_s_idx += si[curr_sub_idx].second.length();
                curr_sub_idx += 1;
            } else {
                ret += s[curr_s_idx];
                curr_s_idx += 1;
            }
        }
        return ret;
    }
};
