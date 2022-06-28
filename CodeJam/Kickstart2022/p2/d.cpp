#include<bits/stdc++.h>
using namespace std;

set<char> vowels{'a', 'e', 'i', 'o', 'u'};

// This code cannot find spells that is inside the string; i.e., we have to find
// spells after trimming some prefix/suffix. This code can only handle cases
// with no trims.

class TrieNode {
public:
    int num_vowels;
    bool finish;
    map<char, TrieNode*> next;
    
    TrieNode() : num_vowels(0), finish(false) {
        next = map<char, TrieNode*>();
    }
    
    TrieNode(int num, bool finished) : num_vowels(num), finish(finished) {
        next = map<char, TrieNode*>();
    }
    
    void insert(string key) {
        TrieNode *curr = this;
        for(char c: key) {
            if ((curr->next).count(c) == 0) {
                int vs = curr->num_vowels;
                if (vowels.find(c) != vowels.end()) {
                    vs += 1;
                }
                curr->next[c] = new TrieNode(vs, false);
            }
            curr = curr->next[c];
        }
        curr->finish = true;
    }
    
    TrieNode* find(string key) {
        TrieNode *curr = this;
        for(char c: key) {
            if ((curr->next).count(c) == 0) return nullptr;
            curr = curr->next[c];
        }
        if (!curr->finish) return nullptr;
        if (curr->num_vowels < 2) return nullptr;
        return curr;
    }
};

void spellchecker(int t) {
    string txt;
    cin >> txt;
    cout << "Case #" << t << ": ";
    int txt_len = txt.length();
    int full_vowels = 0;
    vector<int> num_remaining_vowels(txt_len + 1, 0);
    for(int i=0; i<txt_len; i++) {
        if (vowels.find(txt[i]) != vowels.end()) {
            full_vowels += 1;
            num_remaining_vowels[i + 1] = num_remaining_vowels[i] + 1;
        } else num_remaining_vowels[i + 1] = num_remaining_vowels[i];
    }
    if (full_vowels < 5) {
        cout << "Nothing.\n";
        return;
    }
    for(int &n: num_remaining_vowels) {
        n = full_vowels - n;
    }
    string suffix = "";
    bool valid_end_found = false;
    int valid_end_starts = -1;
    TrieNode *root = new TrieNode();
    for(int i=txt_len-1; i>=0; i--) {
        if (i + i < txt_len - 1) break;
        suffix = txt[i] + suffix;
        if (num_remaining_vowels[i] >= 2){
            root->insert(suffix);
            if (!valid_end_found) {
                valid_end_found = true;
                valid_end_starts = txt_len - 1 - i;
            }
        }
    }
    string prefix = "";
    bool valid_words_found = false;
    for(int i=0; 2 * i < txt_len; i++) {
        if (num_remaining_vowels[i + 1] - num_remaining_vowels[txt_len - i - 1] < 1) break;
        prefix += txt[i];
        TrieNode *queried = root->find(prefix);
        if (queried == nullptr) continue;
        else {
            valid_words_found = true;
            break;
        }
    }
    if (valid_words_found) {
        cout << "Spell!\n";
    } else {
        cout << "Nothing!\n";
    }
}


int main () {
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        spellchecker(t);
    }
    return 0;
}
