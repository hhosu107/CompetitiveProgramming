#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
using pii = pair<int, int>;
int L, R;

// This code only checks whether or not the sapling constructed from the root to
// the leaf is a valid sapling.
// valid: count of distnict numbers on the edges are larger or equal to L,
// smaller or equal to R.
int tree_dfs(int cur_node, unordered_multiset<int> &numbers, vector<vector<pii>> &edges) {
    if (numbers.size() > R) return 0;
    if (edges[cur_node].size() == 0) {
        if (numbers.size() >= L) return 1;
        else return 0;
    } else {
        int sum = 0;
        for(auto p: edges[cur_node]) {
            numbers.insert(p.second);
            int nums = tree_dfs(p.first, numbers, edges);
            auto it = numbers.find(p.second);
            numbers.erase(it);
        }
        return sum;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n >> L >> R;
    vector<vector<pii>> edges = vector<vector<pii>>(n + 1, vector<pii>());
    int h;
    pii t;
    for(int i=0; i<n-1; i++) {
        cin >> h >> t.first >> t.second;
        edges[h].push_back(t);
    }
    unordered_multiset<int> numbers = unordered_multiset<int>();
    int rods = tree_dfs(1, numbers, edges);
    cout << rods << '\n';
    return 0;
}
