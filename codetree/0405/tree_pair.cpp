#include<iostream>
#include<algorithm>
using namespace std;

int tree[4][4];

/* Tree pair: vertical or horizontal length 2 trees are tree pair.
 * We take at most 4 tree paires from the farm,
 * and get the highest height of the tree pairs we selected.
 * Idea: Use bitmask for each tree. When we pick a new pair, compare with
 * bitmask.
 */
int masked_tree_max_bitmask(int k, int masked_bits) {
    if (k == 4) {
        int sum = 0;
        for(int i=0; i < 16; i++) {
            sum += (((1 << i) & (masked_bits)) > 0 ? 1 : 0) * tree[i/4][i%4];
        }
        return sum;
    }
    else {
        int sum = 0;
        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                int next_mask = (1 << (4 * i + j)) + (1 << (4 * i + j + 1));
                if ((masked_bits & next_mask) == 0) {
                    sum = max(sum, masked_tree_max_bitmask(k + 1, masked_bits | next_mask));
                }
                next_mask = (1 << (4 * j + i)) + (1 << (4 * (j + 1) + i));
                if ((masked_bits & next_mask) == 0) {
                    sum = max(sum, masked_tree_max_bitmask(k + 1, masked_bits | next_mask));
                }
            }
        }
        return sum;
    }
}

int main () {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
        cin >> tree[i][j];
    }
    if (n == 2) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                sum += tree[i][j];
        }
        cout << sum << endl;
        return 0;
    } else if (n == 3) {
        int sum = 0;
        int minv = 100;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                sum += tree[i][j];
                minv = min(((i + j) % 2 == 0 ? tree[i][j] : 100), minv);
            }
        }
        cout << sum - minv << endl;
        return 0;
    } else {
        int sum = masked_tree_max_bitmask(0, 0);
        cout << sum << endl;
        return 0;
    }
}
