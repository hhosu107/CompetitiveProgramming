class Solution {
public:
  int BBFS(unordered_set<string> &dictionary, int length,
           unordered_set<string> &beginSet, unordered_set<string> &endSet,
           unordered_set<string> &workingSet) {
    workingSet.clear();
    int n = beginSet.begin()->size();

    for (auto &i : beginSet) {
      dictionary.erase(i);
    }

    for (auto &word : beginSet) {
      for (int i = 0; i < n; ++i) {
        string newWord = word;
        for (char c = 'a'; c <= 'z'; ++c) {
          newWord[i] = c;
          if (dictionary.count(newWord)) {
            if (endSet.count(newWord)) {
              return length + 1;
            }
            workingSet.insert(newWord);
          }
        }
      }
    }

    if (workingSet.size() == 0) {
      return 0;
    }

    if (endSet.size() < workingSet.size()) {
      return BBFS(dictionary, length + 1, endSet, workingSet, beginSet);
    }

    return BBFS(dictionary, length + 1, workingSet, endSet, beginSet);
  }

  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dictionary(wordList.begin(), wordList.end());

    if (dictionary.count(endWord) == 0) {
      return 0;
    }

    unordered_set<string> beginSet;
    beginSet.insert(beginWord);

    unordered_set<string> endSet;
    endSet.insert(endWord);

    unordered_set<string> workingSet;

    return BBFS(dictionary, 1, beginSet, endSet, workingSet);
  }
};
