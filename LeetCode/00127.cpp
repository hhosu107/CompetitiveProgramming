class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    if (beginWord == endWord)
      return 1;
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return 0;
    unordered_map<string, unordered_set<string>> adj_words;
    unordered_map<string, int> word_visited;
    int word_len = beginWord.length();
    for (int i = 0; i < wordList.size(); i++) {
      word_visited[wordList[i]] = 0;
      adj_words[wordList[i]] = unordered_set<string>();
    }
    for (int i = 0; i < wordList.size() - 1; i++) {
      for (int j = i + 1; j < wordList.size(); j++) {
        int diff_cnt = 0;
        for (int k = 0; k < word_len; k++) {
          if (wordList[i][k] != wordList[j][k])
            diff_cnt++;
          if (diff_cnt > 1)
            break;
        }
        if (diff_cnt == 1) {
          adj_words[wordList[i]].insert(wordList[j]);
          adj_words[wordList[j]].insert(wordList[i]);
        }
      }
    }
    if (adj_words.find(beginWord) == adj_words.end()) {
      adj_words[beginWord] = unordered_set<string>();
      for (int i = 0; i < wordList.size(); i++) {
        int diff_cnt = 0;
        for (int k = 0; k < word_len; k++) {
          if (wordList[i][k] != beginWord[k]) {
            diff_cnt += 1;
          }
          if (diff_cnt > 1)
            break;
        }
        if (diff_cnt == 1) {
          adj_words[beginWord].insert(wordList[i]);
        }
      }
    }
    word_visited[beginWord] = 1;
    queue<string> word_seq;
    word_seq.push(beginWord);
    while (!word_seq.empty()) {
      string curr = word_seq.front();
      word_seq.pop();
      for (string s : adj_words[curr]) {
        if (word_visited[s] != 0)
          continue;
        if (s == endWord)
          return word_visited[curr] + 1;
        word_visited[s] = word_visited[curr] + 1;
        word_seq.push(s);
      }
    }
    return 0;
  }
};
