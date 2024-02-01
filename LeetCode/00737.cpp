class Solution {
public:
  bool areSentencesSimilarTwo(vector<string> &sentence1,
                              vector<string> &sentence2,
                              vector<vector<string>> &similarPairs) {
    if (sentence1.size() != sentence2.size())
      return false;
    map<string, set<string>> similarPairMap;
    for (vector<string> p : similarPairs) {
      if (similarPairMap.find(p[0]) == similarPairMap.end()) {
        similarPairMap[p[0]] = set<string>();
      }
      // similarPairMap[p[0]].insert(p[0]);
      similarPairMap[p[0]].insert(p[1]);
      if (similarPairMap.find(p[1]) == similarPairMap.end()) {
        similarPairMap[p[1]] = set<string>();
      }
      // similarPairMap[p[1]].insert(p[0]);
      similarPairMap[p[1]].insert(p[0]);
    }
    for (int i = 0; i < sentence1.size(); i++) {
      if (sentence1[i] == sentence2[i])
        continue;
      if (similarPairMap.find(sentence1[i]) == similarPairMap.end() ||
          similarPairMap.find(sentence2[i]) == similarPairMap.end()) {
        return false;
      }
      queue<string> trans;
      set<string> visited_strings;
      trans.push(sentence1[i]);
      visited_strings.insert(sentence1[i]);
      bool pair_found = false;
      while (!trans.empty()) {
        string curr = trans.front();
        if (curr == sentence2[i]) {
          pair_found = true;
          break;
        }
        trans.pop();
        for (auto it = similarPairMap[curr].begin();
             it != similarPairMap[curr].end(); it++) {
          if (visited_strings.find(*it) == visited_strings.end()) {
            trans.push(*it);
            visited_strings.insert(*it);
          }
        }
      }
      if (pair_found)
        continue;
      return false;
    }
    return true;
  }
};
