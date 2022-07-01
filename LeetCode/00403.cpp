class Solution {
public:
    using ll = long long;
    map<int, int> n_to_k;
    bool canCross(vector<int>& stones) {
        
        using pll = pair<ll, ll>;
        using pii = pair<int, int>;
        if (stones[1] > 1) return false;
        ll max_n = stones[stones.size() - 1];
        ll tri_sum = 1;
        ll tri_k = 1;
        while (tri_sum <= max_n) {
            n_to_k[(int)tri_sum] = (int)tri_k;
            tri_k += 1;
            tri_sum += tri_k;
        }
        map<int, set<pii>> possible_prev_jumpsize;
        possible_prev_jumpsize[1] = set<pii>{{0, 1}};
        for(int i=2; i<stones.size(); i++) {
            /* What is max possible steps? that is k satisfying (k + 1)k / 2 <= n < (k + 2)(k + 1) / 2. */
            auto it = n_to_k.upper_bound(stones[i]);
            it--;
            ll max_k = it->second;
            for(int j=i-1; j>0 && stones[i] - stones[j] <= max_k; j--) {
                for (pii p : possible_prev_jumpsize[j]) {
                    if (abs(p.second - (stones[i] - stones[j])) <= 1) {
                        possible_prev_jumpsize[i].insert({j, stones[i] - stones[j]});
                    }
                }
            }
        }
        return !possible_prev_jumpsize[stones.size() - 1].empty();
    }
};

// Amortized time complexity: O(n^2 sqrt(n)).
// 아이디어: 현재의 돌 위치가 n이라면, n에 도달할 때의 최대 step 길이 k 는
// k(k+1) / 2 <= n < (k + 1)(k + 2) / 2를 만족해야 한다.
// 따라서,
// 직전 돌들에 이전 어떤 돌들에서 reachable했는지 저장해둔 다음,
// 현재의 돌에서 k까지만 떨어져있는 돌들의 직전 reachability를 모두 검색해서, 그
// 중 현재 돌과의 거리 dist와의 차이가 -1 ~ 1 사이인 돌들을 저장한다.
// 문제: 한 번 만든 '직전 돌 set'을 여러 번 반복해야 한다.
// 이 때문에 개선된 result: 현재의 돌에 도착했던 step만을 저장한 다음, 현재의
// 돌에서 다음 step들에 도착할 수 있는 possibility만 센다. (00403-faster)
