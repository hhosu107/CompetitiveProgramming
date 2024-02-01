class TrieNode {
public:
  vector<string> matched_strings;
  int matched_string_size = 0;
  unordered_map<char, TrieNode *> children;
  TrieNode() {
    matched_strings = vector<string>();
    children = unordered_map<char, TrieNode *>();
  }
  static char char_mapper(char c) {
    char lc = tolower(c);
    set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    if (vowels.find(lc) != vowels.end()) {
      return '-';
    }
    return lc;
  }
  static bool case_insensitive_equality(string pattern, string query) {
    transform(pattern.begin(), pattern.end(), pattern.begin(),
              [](unsigned char c) { return tolower(c); });
    transform(query.begin(), query.end(), query.begin(),
              [](unsigned char c) { return tolower(c); });
    return pattern == query;
  }

  static bool wildcard_equality(string pattern, string query) {
    transform(pattern.begin(), pattern.end(), pattern.begin(),
              [](unsigned char c) {
                char lc = tolower(c);
                set<char> vowels{'a', 'e', 'i', 'o', 'u'};
                return vowels.find(lc) != vowels.end() ? '-' : lc;
              });
    transform(query.begin(), query.end(), query.begin(), [](unsigned char c) {
      char lc = tolower(c);
      set<char> vowels{'a', 'e', 'i', 'o', 'u'};
      return vowels.find(lc) != vowels.end() ? '-' : lc;
    });
    return pattern == query;
  }
  void insert_string(string word) {
    TrieNode *root = this;
    for (char w : word) {
      char lc = char_mapper(w);
      if (root->children.count(lc) == 0) {
        root->children[lc] = new TrieNode();
      }
      root = root->children[lc];
    }
    root->matched_strings.push_back(word);
    root->matched_string_size += 1;
  }
  string query_exists(string word) {
    TrieNode *root = this;
    for (char w : word) {
      char lc = char_mapper(w);
      if (root->children.count(lc) == 0) {
        return "";
      }
      root = root->children[lc];
    }
    if (root->matched_string_size == 0)
      return "";
    // exact equality
    for (string m : root->matched_strings) {
      if (m == word)
        return m;
    }
    // case insensitive_equality
    for (string m : root->matched_strings) {
      if (case_insensitive_equality(m, word))
        return m;
    }
    // wildcard_equality
    for (string m : root->matched_strings) {
      if (wildcard_equality(m, word))
        return m;
    }
    return "";
  }
};

class Solution {
public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    // Sol) Use trie, but save the matched string's list.
    // When a character is one of upper/lower vowels, that character is matched
    // with a special character '-'.
    TrieNode *root = new TrieNode();
    for (string w : wordlist) {
      root->insert_string(w);
    }
    vector<string> result(queries.size(), "");
    for (int i = 0; i < queries.size(); i++) {
      result[i] = root->query_exists(queries[i]);
    }
    return result;
  }
};
