// NON-TLE version. Trie once more....

class TrieNode {
public:
  map<char, TrieNode *> children;
  bool word;
  TrieNode() {
    children = map<char, TrieNode *>();
    word = false;
  }
};

class StreamChecker {
public:
  TrieNode *trie;
  vector<char> stream;
  StreamChecker(vector<string> &words) {
    trie = new TrieNode();
    stream = vector<char>();
    for (string w : words) {
      TrieNode *node = trie;
      reverse(w.begin(), w.end());
      for (char c : w) {
        if (node->children.count(c) == 0) {
          node->children[c] = new TrieNode();
        }
        node = node->children[c];
      }
      node->word = true;
    }
  }

  bool query(char letter) {
    stream.push_back(letter);
    TrieNode *node = trie;
    for (int i = stream.size() - 1; i >= 0; i--) {
      if (node->word) {
        return true;
      }
      if (node->children.count(stream[i]) == 0) {
        return false;
      }
      node = node->children[stream[i]];
    }
    return node->word;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

// TLE version. Even though I did the 가지치기, it didn't work.
class StreamChecker {
public:
  set<string> suffix_dict;
  vector<string> curr_suffices;
  int curr_suffix_idx;
  StreamChecker(vector<string> &words) {
    for (string w : words)
      suffix_dict.insert(w);
    curr_suffices = vector<string>(200, "");
    curr_suffix_idx = 0;
  }

  bool query(char letter) {
    bool found = false;
    if (curr_suffix_idx < 200) {
      for (int i = 0; i < curr_suffix_idx; i++) {
        curr_suffices[i] += letter;
        if (suffix_dict.find(curr_suffices[i]) != suffix_dict.end()) {
          found = true;
        }
      }
      curr_suffices[curr_suffix_idx] = string(1, letter);
      if (suffix_dict.find(curr_suffices[curr_suffix_idx]) !=
          suffix_dict.end()) {
        found = true;
      }
    } else {
      for (int i = 0; i < 200; i++) {
        if (curr_suffix_idx % 200 == i) {
          curr_suffices[i] = string(1, letter);
        } else {
          curr_suffices[i] += letter;
        }
        if (suffix_dict.find(curr_suffices[i]) != suffix_dict.end()) {
          found = true;
        }
      }
    }
    curr_suffix_idx += 1;
    return found;
  }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
