#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;

class TrieNode {
private:
  unordered_map<char, TrieNode *> children;
  bool terminates = false;
  int query_count = 0;
public:
  TrieNode() {
    children = unordered_map<char, TrieNode *>();
  }
  bool is_word() {
    return terminates;
  }
  void set_word() {
    terminates = true;
  }
  int queried_count() {
    return query_count;
  }
  void add_queried_count(int queried_count) {
    query_count += queried_count;
  }
  void add_word(string word, int queried_count) {
    TrieNode *root = this;
    if (word.length() == 0) {
      return;
    }
    for(char c: word) {
      if (root->getChild(c) == nullptr) {
        root->setChild(c);
      }
      root = root->getChild(c);
    }
    root->set_word();
    root->add_queried_count(queried_count);
  }
  TrieNode* getChild(char c) {
    if (children.count(c) == 0) {
      return nullptr;
    }
    return children[c];
  }
  void setChild(char c) {
    if (children.count(c) != 0) {
      return;
    }
    children[c] = new TrieNode();
  }
  TrieNode* find_word(string word) {
    TrieNode *root = this;
    for(char c: word) {
      if (root->getChild(c) == nullptr) {
        return nullptr;
      }
      root = root->getChild(c);
    }
    if (!root->is_word()) return nullptr;
    return root;
  }
};

int main () {
  TrieNode *root = new TrieNode();
  root->add_word("google", 5);
  root->add_word("apple", 3);
  root->add_word("gmarket", 2);
  root->add_word("nvidia", 4);
  root->add_word("meta", 1);
  cout << root->find_word("google")->queried_count() << endl;
  root->add_word("google", 4);
  cout << root->find_word("google")->queried_count() << endl;
  return 0;
}

