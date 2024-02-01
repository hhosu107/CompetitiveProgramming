using pii = pair<int, int>;

const int ALPHABET_SIZE = 62;

class TrieNode {
  TrieNode *children[ALPHABET_SIZE];
  bool is_end_of_word;

public:
  TrieNode() {
    this->is_end_of_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      children[i] = nullptr;
    }
  }

  void insert(string word) {
    TrieNode *curr = this;
    for (int i = 0; i < word.length(); i++) {
      int index;
      if (word[i] >= '0' && word[i] <= '9')
        index = (int)(word[i] - '0');
      else if (word[i] >= 'a' && word[i] <= 'z')
        index = 10 + (int)(word[i] - 'a');
      else
        index = 26 + (int)(word[i] - 'A');
      if (curr->children[index] == nullptr) {
        curr->children[index] = new TrieNode();
      }
      curr = curr->children[index];
    }
    curr->is_end_of_word = true;
  }

  bool search(string word) {
    if (this == nullptr) {
      return false;
    }
    TrieNode *curr = this;
    for (int i = 0; i < word.length(); i++) {
      int index;
      if (word[i] >= '0' && word[i] <= '9')
        index = (int)(word[i] - '0');
      else
        index = 10 + (int)(word[i] - 'a');
      curr = curr->children[index];
      if (curr == nullptr)
        return false;
    }
    return curr->is_end_of_word;
  }
};

class Solution {

public:
  string addBoldTag(string s, vector<string> &words) {
    if (words.size() == 0)
      return s;
    TrieNode *dict = new TrieNode();
    int wordlen_max = 0;
    int wordlen_min = 1001;
    for (string w : words) {
      dict->insert(w);
      wordlen_max = max((int)w.length(), wordlen_max);
      wordlen_min = min((int)w.length(), wordlen_min);
    }
    stack<pii> bolds;
    int curr_start = 0, index = 0, curr_foundmax = 0;
    bool in_pattern = false;
    while (index + wordlen_min <= (int)s.length()) {
      string base_substr = s.substr(index, wordlen_min - 1);
      for (int i = wordlen_min; i + index <= (int)s.length(); i++) {
        base_substr += s[i + index - 1];
        if (dict->search(base_substr)) {
          if (!in_pattern) {
            curr_start = index;
            curr_foundmax = index + i;
            in_pattern = true;
          } else {
            curr_foundmax = max(curr_foundmax, index + i);
          }
        }
      }
      if (index >= curr_foundmax && in_pattern) {
        if (bolds.empty()) {
          bolds.push({curr_start, curr_foundmax});
        } else {
          pii stop = bolds.top();
          if (stop.second == curr_start) {
            bolds.pop();
            bolds.push({stop.first, curr_foundmax});
          } else {
            bolds.push({curr_start, curr_foundmax});
          }
        }
        in_pattern = false;
      }
      index += 1;
    }
    if (in_pattern) {
      if (bolds.empty()) {
        bolds.push({curr_start, curr_foundmax});
      } else {
        pii stop = bolds.top();
        if (stop.second == curr_start) {
          bolds.pop();
          bolds.push({stop.first, curr_foundmax});
        } else {
          bolds.push({curr_start, curr_foundmax});
        }
      }
      in_pattern = false;
    }
    vector<pii> found_indices_rev;
    while (!bolds.empty()) {
      pii stop = bolds.top();
      bolds.pop();
      found_indices_rev.push_back(stop);
    }
    reverse(found_indices_rev.begin(), found_indices_rev.end());
    if (found_indices_rev.size() == 0) {
      return s;
    }
    cout << found_indices_rev.size() << endl;
    for (pii f : found_indices_rev) {
      cout << f.first << " " << f.second << endl;
    }
    string result = "";
    result += s.substr(0, found_indices_rev[0].first);
    for (int i = 0; i < found_indices_rev.size() - 1; i++) {
      result += "<b>";
      result +=
          s.substr(found_indices_rev[i].first,
                   found_indices_rev[i].second - found_indices_rev[i].first);
      result += "</b>";
      result += s.substr(found_indices_rev[i].second,
                         found_indices_rev[i + 1].first -
                             found_indices_rev[i].second);
    }
    result += "<b>";
    result +=
        s.substr(found_indices_rev[found_indices_rev.size() - 1].first,
                 found_indices_rev[found_indices_rev.size() - 1].second -
                     found_indices_rev[found_indices_rev.size() - 1].first);
    result += "</b>";
    result += s.substr(found_indices_rev[found_indices_rev.size() - 1].second);
    return result;
  }
};
