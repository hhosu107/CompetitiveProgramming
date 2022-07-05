#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    struct Pattern {
        string first, second, third;
        Pattern() : first(""), second(""), third("") {}
        Pattern(string f, string s, string t) : first(f), second(s), third(t) {}
        void next_pattern(string fourth) {
            first = second;
            second = third;
            third = fourth;
        }
        void operator=(const Pattern &o) {
            first = o.first;
            second = o.second;
            third = o.third;
        }
        bool operator<(const Pattern &o) const {
            if (first != o.first) return first < o.first;
            if (second != o.second) return second < o.second;
            if (third != o.third) return third < o.third;
            return false;
        }
    };
    struct VisitLog {
        int timestamp;
        string website;
        VisitLog() : timestamp(0), website("") {}
        VisitLog(int t, string w) : timestamp(t), website(w) {}
        bool operator<(const VisitLog &o) const {
            return timestamp < o.timestamp; // To perform the stable sort.
        }
    };
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string, vector<VisitLog>> user_log;
        for(int i=0; i<username.size(); i++) {
            if (user_log.count(username[i]) == 0) {
                user_log[username[i]] = vector<VisitLog>();
            }
            user_log[username[i]].push_back({timestamp[i], website[i]});
        }
        for (auto &kv: user_log) {
            stable_sort(kv.second.begin(), kv.second.end());
        }
        map<Pattern, int> pattern_count;
        for (const auto [key, v]: user_log) {
            if (v.size() < 3) continue;
            for(int i=0; i<v.size() - 2; i++) {
                for(int j=i+1; i<v.size() - 1; j++) {
                    for(int k=j+1; k<v.size(); k++) {
                        Pattern found = Pattern(v[i].website, v[j].website, v[k].website);
                        if (pattern_count.count(found) == 0) {
                            pattern_count[found] = 0;
                        }
                        pattern_count[found] += 1;
                    }
                }
            }
        }
        int max_pattern_count = -1;
        Pattern max_pattern = Pattern();
        for (const auto &[k, v]: pattern_count) {
            if (v > max_pattern_count) {
                max_pattern_count = v;
                max_pattern = k;
            }
        }
        vector<string> ret_pattern {max_pattern.first, max_pattern.second, max_pattern.third};
        return ret_pattern;
    }
};

int main () {
    Solution x = Solution();
    vector<string> username {"z", "z", "z", "z"};
    vector<int> timestamp {436363475, 70146388, 386655081, 797150921};
    vector<string> website {"wnaaxbfhxp","mryxsjc","oz","wlarkzzqht"};
    vector<string> mostVisitedPattern = x.mostVisitedPattern(username, timestamp, website);
    for(auto str: mostVisitedPattern) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
