class Solution {
public:
  string reverseWords(string s) {
    string curr_word = "";
    vector<string> words;
    for (char c : s) {
      if (c == ' ') {
        if (curr_word != "") {
          words.push_back(curr_word);
        }
        curr_word = "";
      } else
        curr_word += c;
    }
    if (curr_word != "")
      words.push_back(curr_word);
    if (words.size() == 0)
      return "";
    reverse(words.begin(), words.end());
    string ret_words = words[0];
    for (int i = 1; i < words.size(); i++) {
      ret_words += ' ';
      ret_words += words[i];
    }
    return ret_words;
  }
};
