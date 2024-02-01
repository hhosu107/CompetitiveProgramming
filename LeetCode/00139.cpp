class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
  bool is_word = false;
  TrieNode() {
    children = unordered_map<char, TrieNode *>();
    is_word = false;
  }
  void insert_word(string word) {
    TrieNode *curr = this;
    for (char c : word) {
      if (curr->children.find(c) == curr->children.end()) {
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
    }
    curr->is_word = true;
  }
  TrieNode *move_node(char c) {
    if (this->children.find(c) == this->children.end()) {
      return nullptr;
    }
    return this->children[c];
  }
};

struct TrieNodePos {
  TrieNode *loc;
  int index;
  TrieNodePos(TrieNode *curr, int idx) {
    loc = curr;
    index = idx;
  }
  bool operator==(const TrieNodePos &o) const {
    return (loc == o.loc && index == o.index);
  }
  bool operator<(const TrieNodePos &o) const {
    return index < o.index || (index == o.index && loc < o.loc);
  }
};

class Solution {
public:
  void move_queue_once(queue<TrieNodePos> &q, set<TrieNodePos> &ts, string &s,
                       int len, TrieNode *root) {
    TrieNodePos curr = q.front();
    q.pop();
    ts.erase(curr);
    if (curr.index == len)
      return;
    TrieNode *next_curr = curr.loc->move_node(s[curr.index]);
    if (next_curr == nullptr)
      return;
    if (next_curr->is_word) {
      TrieNodePos new_node{root, curr.index + 1};
      if (ts.find(new_node) == ts.end()) {
        q.push(new_node);
        ts.insert(new_node);
      }
    }
    curr.index += 1;
    curr.loc = next_curr;
    if (ts.find(curr) == ts.end()) {
      q.push(curr);
      ts.insert(curr);
    }
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    int len = s.length();
    TrieNode *root = new TrieNode();
    for (string w : wordDict) {
      root->insert_word(w);
    }
    TrieNodePos root_pos{root, 0};
    queue<TrieNodePos> word_split_queue;
    set<TrieNodePos> word_split_nodes;
    word_split_queue.push(root_pos);
    word_split_nodes.insert(root_pos);
    while (!word_split_queue.empty()) {
      TrieNodePos curr = word_split_queue.front();
      if (curr.loc == root && curr.index == len) {
        return true;
      }
      move_queue_once(word_split_queue, word_split_nodes, s, len, root);
    }
    return false;
  }
};
