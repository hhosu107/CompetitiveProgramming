
bool is_vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
class Solution {
public:
  set<string> words_perfect;
  map<string, vector<string>> words_lower;
  map<string, vector<string>> words_devowel;
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    words_perfect = set<string>();
    words_lower = map<string, vector<string>>();
    words_devowel = map<string, vector<string>>();
    for (string w : wordlist) {
      string w_orig = w;
      words_perfect.insert(w);
      transform(w.begin(), w.end(), w.begin(),
                [](char c) { return tolower(c); });
      if (words_lower.count(w) == 0) {
        words_lower[w] = vector<string>();
      }
      words_lower[w].push_back(w_orig);
      transform(w.begin(), w.end(), w.begin(), [](char c) {
        if (is_vowel(c)) {
          return '*';
        }
        return c;
      });
      if (words_devowel.count(w) == 0) {
        words_devowel[w] = vector<string>();
      }
      words_devowel[w].push_back(w_orig);
    }
    vector<string> answer;
    for (string q : queries) {
      if (words_perfect.find(q) != words_perfect.end()) {
        answer.push_back(q);
        continue;
      }
      transform(q.begin(), q.end(), q.begin(),
                [](char c) { return tolower(c); });
      if (words_lower.find(q) != words_lower.end()) {
        answer.push_back(words_lower[q][0]);
        continue;
      }
      transform(q.begin(), q.end(), q.begin(), [](char c) {
        if (is_vowel(c)) {
          return '*';
        }
        return c;
      });
      if (words_devowel.find(q) != words_devowel.end()) {
        answer.push_back(words_devowel[q][0]);
        continue;
      }
      answer.push_back("");
    }
    return answer;
  }
};
// Not have to use trie, just use hashmap<string, vector<string>>.
