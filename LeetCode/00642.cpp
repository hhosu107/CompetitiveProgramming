using pii = pair<int, int>;
using pis = pair<int, string>;
using pss = pair<string, string>;
const int ALPHABET_SIZE = 28;

int alphabet_idx(char x) {
    if (x >= 'a' && x <= 'z') {
        return (int)(x - 'a');
    } else if (x == '#') {
        return 26;
    } else return 27;
}

char idx_alphabet(int idx) {
    if (0 <= idx && idx <= 25) {
        return (char)(idx + 'a');
    } else if (idx == 26) {
        return '#';
    } else return ' ';
}

class TrieNode {
    map<int, TrieNode*> children;
    int queried_count;
public:
    TrieNode () {
        this->queried_count = 0;
        children = map<int, TrieNode*>();
    }
    void insert(string word, int count) {
        TrieNode *curr = this;
        for(int i=0; i<word.length(); i++) {
            int index = alphabet_idx(word[i]);
            if (curr->children.find(index) == curr->children.end()){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->queried_count += count;
    }
    
    vector<pis> prefix_search(string prefix) {
        TrieNode *curr = this;
        vector<pis> ret;
        for(char c : prefix) {
            if (curr->children.find(alphabet_idx(c)) == curr->children.end()) {
                return ret;
            }
            curr = curr->children[alphabet_idx(c)];
        }
        using pts = pair<TrieNode*, string>;
        stack<pts> node_prefix;
        node_prefix.push({curr, prefix}); // curr points the prefix.
        while (!node_prefix.empty()) {
            pts hd = node_prefix.top();
            node_prefix.pop();
            if ((hd.first)->queried_count > 0) {
                ret.push_back({(hd.first)->queried_count, hd.second});
            }
            for (auto it=((hd.first)->children).begin(); it != ((hd.first)->children).end(); it++)
                node_prefix.push({it->second, hd.second + idx_alphabet(it->first)});
        }
        return ret;
    }
};

/*
 * If we use TrieNode as subclass of this class (It is possible since it is
 * identical to type definition), we can track current position and perform +1
 * character search for each character insert, not full search from the root.
 * Reference: https://leetcode.com/problems/design-search-autocomplete-system/discuss/105393/C%2B%2B-Trie-and-DFS-solution-beats-80
 * */
class AutocompleteSystem {
public:
    // Sol) Trie, but the ending-indicator is not a boolean but an integer that were typed.
    string curr_stream;
    TrieNode *root;
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        curr_stream = "";
        root = new TrieNode();
        for(int i=0; i<sentences.size(); i++) {
            root->insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> ret;
        if (c == '#') {
            root->insert(curr_stream, 1);
            curr_stream = "";
            return ret;
        } else {
            curr_stream += c;
            vector<pis> queried_results = root->prefix_search(curr_stream);
            auto comp = [](const pis &a, const pis &b) {
                if (a.first < b.first) return true;
                if (a.first > b.first) return false;
                if (a.second > b.second) return true;
                if (a.second < b.second) return false;
                return false;
            };
            priority_queue<pis, vector<pis>, decltype(comp)> top_sentences(comp);
            for(pis q: queried_results) {
                top_sentences.push(q);
            }
            int found_cnt = 0;
            while(found_cnt < 3 && !top_sentences.empty()) {
                pis curr = top_sentences.top();
                top_sentences.pop();
                ret.push_back(curr.second);
                found_cnt += 1;
            }
            return ret;
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
