class Solution {
public:
  int kthSmallest(vector<vector<int>> &mat, int k) {
    using pivi = pair<int, vector<int>>;
    int n = mat.size(), m = mat[0].size();
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
      sum += mat[i][0];
    set<vector<int>> us;
    priority_queue<pivi, vector<pivi>, greater<pivi>> pq;
    pq.push({sum, vector<int>(n, 0)});
    while (!pq.empty()) {
      pivi p = pq.top();
      pq.pop();
      // check if inserted before
      if (!us.insert(p.second)
               .second) // set's insert function returns a pair: iterator and
                        // succeed/fail. iterator returns the location of the
                        // inserted element, and pass/fail returns was it
                        // successful or not (already existed).
        continue;
      sum = p.first;
      if (++cnt == k) // kth smallest
        return p.first;
      for (int i = 0; i < n; i++) {
        if (++p.second[i] < m) {
          pq.push({sum + mat[i][p.second[i]] - mat[i][p.second[i] - 1],
                   p.second}); // index increasing doesn't make out of index
        }
        --p.second[i];
      }
    }
    // void return. unreachable by restriction of k.
    return 0;
  }
};
