class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // wage/quality -> max(min) -> quality 너무 높아서 wage가 높을 수밖에 없는 사람일 경우 이것도 망가진다.
        // n명 중 k명을 고른 상태에서.
        // Idea: 우리가 wage/quality 비율이 x번째로 나쁜 사용자를 무조건 써야 한다면, 그 때의 비용은 quality 합 * 그 wage/quality이다. 따라서 quality 합을 최소화해야 한다.
        // 그걸 max priority queue로 k명 유지해가며 구한다. 변화량 = (x번째 quality - 빠져나온 quality).
        int N = quality.size();
        using pdi = pair<double, int>;
        vector<pdi> ratio_wq(N);
        for(int i=0; i<N; i++)
            ratio_wq[i] = make_pair(wage[i] * 1.0 / quality[i], quality[i]);
        sort(ratio_wq.begin(), ratio_wq.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
        int quality_cnt = 0;
        priority_queue<int> q; // max heap
        for(int i=0; i<k; i++) {
            quality_cnt += ratio_wq[i].second;
            q.push(ratio_wq[i].second);
        }
        double ans = quality_cnt * ratio_wq[k-1].first; // Since we have maximum wage/quality ratio at K-1 th worker.
        for(int i=k; i<N; i++) {
            q.push(ratio_wq[i].second);
            quality_cnt += ratio_wq[i].second;
            quality_cnt -= q.top();
            q.pop();
            ans = min(ans, quality_cnt * ratio_wq[i].first); // If ratio_sq[i]'th worker immediately popped, it means the sum of wage remains. Otherwise, use that wage/quality ratio.
        }
        return ans;
    }
};
