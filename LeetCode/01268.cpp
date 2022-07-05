class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word = false;
    string word = "";
    
    TrieNode () {
        children = unordered_map<char, TrieNode*>();
    }
    void insert(string word) {
        TrieNode *root = this;
        for (char c: word) {
            if (root->children.count(c) == 0) {
                root->children[c] = new TrieNode();
            }
            root = root->children[c];
        }
        root->is_word = true;
        root->word = word;
    }
    pair<vector<string>, TrieNode*> suggestions(char c) {
        if (this == nullptr) {
            return make_pair(vector<string>(), nullptr);
        }
        if (this->children.count(c) == 0) {
            return make_pair(vector<string>(), nullptr);
        }
        TrieNode *ret = this->children[c];
        
        vector<string> found_strings;
        found_strings_under_root(ret, found_strings);
        sort(found_strings.begin(), found_strings.end());
        int len = found_strings.size();
        vector<string> found_strings_suggestion;
        for(int i=0; i<min(len, 3); i++) {
            found_strings_suggestion.push_back(found_strings[i]);
        }
        return make_pair(found_strings_suggestion, ret);
    }
    void found_strings_under_root(TrieNode* curr, vector<string> &curr_found) {
        if (curr->is_word) {
            curr_found.push_back(curr->word);
        }
        for(const auto &[k, v]: curr->children) {
            found_strings_under_root( v, curr_found);
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> suggested_word_lists = vector<vector<string>>();
        TrieNode* root = new TrieNode();
        for(string p: products) {
            root->insert(p);
        }
        string word = "";
        for(char c: searchWord) {
            word += c;
            if (root == nullptr) {
                suggested_word_lists.push_back(vector<string>());
                continue;
            }
            pair<vector<string>, TrieNode*> next_ret = root->suggestions(c);

            root = next_ret.second;
            suggested_word_lists.push_back(next_ret.first);
        }
        return suggested_word_lists;
    }
};
