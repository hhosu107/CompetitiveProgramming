class TrieNode {
public:
    string word;
    unordered_map<char, TrieNode*> childs;
    bool is_word;
    TrieNode () {
        word = "";
        childs = unordered_map<char, TrieNode*>();
        is_word = false;
    }
    void insert (string w) {
        TrieNode* curr = this;
        for(char c: w) {
            if (curr->childs.find(c) == curr->childs.end()) {
                curr->childs[c] = new TrieNode();
            }
            curr = curr->childs[c];
        }
        curr->word = w;
        curr->is_word = true;
    }
    bool continuousFound(string w) {
        TrieNode* curr = this;
        for(char c: w) {
            if (!curr->childs[c]->is_word) {
                return false;
            }
            curr = curr->childs[c];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string w: words)
            root->insert(w);
        string longest = "";
        int longest_len = 0;
        for(string w: words) {
            bool found = root->continuousFound(w);
            if (found) {
                if (longest_len < w.length() || (longest_len == w.length() && longest > w)) {
                    longest = w;
                    longest_len = w.length();
                }
            }
        }
        return longest;
    }
};

