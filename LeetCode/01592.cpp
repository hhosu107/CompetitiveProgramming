class Solution {
public:
  string reorderSpaces(string text) {
    vector<string> words;
    int len = text.length();
    int space_len = 0;
    int idx = 0;
    while (idx < len) {
      if (text[idx] == ' ') {
        space_len += 1;
        idx += 1;
      } else {
        string word = "";
        while (idx < len && text[idx] != ' ') {
          word += text[idx];
          idx += 1;
        }
        words.push_back(word);
      }
    }
    int words_count = words.size();
    int equal_spaces = (words_count == 1 ? 0 : space_len / (words_count - 1));
    string rearranged_text = "";
    for (auto w : words) {
      rearranged_text += w;
      if (space_len > 0) {
        string spaces(min(equal_spaces, space_len), ' ');
        rearranged_text += spaces;
      }
      space_len -= equal_spaces;
    }
    if (space_len > 0) {
      string leftover_spaces(space_len, ' ');
      rearranged_text += leftover_spaces;
    }
    return rearranged_text;
  }
};
