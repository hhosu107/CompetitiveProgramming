class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        map<string, set<string>> similarPairMap;
        for(vector<string> p: similarPairs) {
            if (similarPairMap.find(p[0]) == similarPairMap.end()) {
                similarPairMap[p[0]] = set<string>();
            } 
            similarPairMap[p[0]].insert(p[1]);
            if (similarPairMap.find(p[1]) == similarPairMap.end()) {
                similarPairMap[p[1]] = set<string>();
            } 
            similarPairMap[p[1]].insert(p[0]);
        }
        for(int i=0; i<sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) continue;
            if (similarPairMap.find(sentence1[i]) != similarPairMap.end()) {
                if (similarPairMap[sentence1[i]].find(sentence2[i]) != similarPairMap[sentence1[i]].end()) continue;
            }
            if (similarPairMap.find(sentence2[i]) != similarPairMap.end()) {
                if (similarPairMap[sentence2[i]].find(sentence1[i]) != similarPairMap[sentence2[i]].end()) continue;
            }
            return false;
        }
        return true;
    }
};
