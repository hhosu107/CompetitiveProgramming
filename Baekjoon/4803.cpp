// 4803: Find number of trees
// Sol) With union-find, check a subgraph is a tree or not.
#undef BOJ

#ifdef BOJ
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>

#ifdef BOJ
#include <immintrin.h>
#include <smmintrin.h>
#endif

using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
#define byte unsigned char
typedef unsigned int uint;
typedef unsigned long long int ulli;

int unf[1000];
bool not_tree[1000];

int _find(int x) {
    return unf[x] == x ? x : (unf[x] = _find(unf[x]));
}

bool _union(int x, int y) {
    x = _find(x);
    y = _find(y);
    if (x == y) {
        if (not_tree[x]) {
            return false;
        }
        not_tree[x] = true;
        return true;
    }
    bool res = !(not_tree[x] && not_tree[y]);
    unf[x] = y;
    not_tree[y] = not_tree[x] || not_tree[y];
    return res;
}

int main() {
    int n, m;
    for (int t = 1; scanf("%d%d", &n, &m) == 2 && n && m; ++t) {
        iota(unf, unf + n + 1, 0);
        fill(not_tree, not_tree + n + 1, false);
        int cnt = n;
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (_union(a, b)) {
                --cnt;
            }
        }
        if (cnt > 1) printf("Case %d: A forest of %d trees.\n", t, cnt);
        else if (cnt == 1) printf("Case %d: There is one tree.\n", t);
        else printf("Case %d: No trees.\n", t);
    }
    return 0;
}

