class StrVal {
private:
    vector<int> char_cnt;
    int chars;
public:
    StrVal () {
        char_cnt = vector<int>(26);
        chars = 0;
    }
    StrVal (string s) : StrVal() {
        chars = s.length();
        for(char c: s){
            char_cnt[c - 'a']++;
        }
    }
    StrVal& operator+=(const StrVal& o) {
        for(int i=0; i<26; i++)
            this->char_cnt[i] += o.char_cnt[i];
        this->chars += o.chars;
        return *this;
    }
    StrVal& operator-=(const StrVal& o) {
        for(int i=0; i<26; i++)
            this->char_cnt[i] -= o.char_cnt[i];
        this->chars -= o.chars;
        return *this;
    }
    StrVal& operator=(const StrVal& o) {
        for(int i=0; i<26; i++)
            this->char_cnt[i] = o.char_cnt[i];
        return *this;
    }
    int check_unique () {
        for(int i=0; i<26; i++) {
            if (char_cnt[i] > 1) return 0;
        }
        return chars;
    }
};

class Solution {
public:
    int uniqueCnt(vector<StrVal>& str_vals, int n, int k, StrVal &origin) {
        if (k == n) {
            return origin.check_unique();
        }
        origin += str_vals[k];
        int included = uniqueCnt(str_vals, n, k + 1, origin);
        origin -= str_vals[k];
        int not_included = uniqueCnt(str_vals, n, k + 1, origin);
        return max(included, not_included);
    }
    
    int maxLength(vector<string>& arr) {
        vector<StrVal> str_vals;
        for(int i=0; i<arr.size(); i++) {
            str_vals.emplace_back(StrVal(arr[i]));
        }
        StrVal origin = StrVal();
        return uniqueCnt(str_vals, arr.size(), 0, origin);
    }
};
