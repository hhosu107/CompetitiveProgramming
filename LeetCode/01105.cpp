class Solution {
public:
  int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    int n = books.size();
    vector<int> dp(n + 1, 0); // min height for book up to i (starting from 0)
    dp[0] = 0;

    // doing dp
    for (int i = 0; i < n; i++) {
      dp[i + 1] =
          dp[i] +
          books[i][1]; // maximum value: i'th book is placed at the new layer.
      int sum = 0, h = 0;
      for (int j = i; j >= 0; j--) // Sweep previous books in the reverse order
      {
        sum += books[j][0];   // Try to add books that can fit within shelfWidth
        if (sum > shelfWidth) // Impossible if exceeds
        {
          break;
        } else // Possible
        {
          h = max(h, books[j][1]); // Since only the new book we watch affects
                                   // the maximum height, O(1)
          dp[i + 1] = min(dp[j] + h,
                          dp[i + 1]); // We pull out j'th book to the new layer.
                                      // So we have sum of heights at j-1th book
                                      // and the height h. Compare dp[j] + h and
                                      // dp[i + 1] and update dp[i + 1].
        }
      }
    }
    return dp[n];
  }
};
// DP structure follows.
// DP[i] = min_(j<i) (DP[j] + max_(k \in [j + 1, i])(height[k])), where width
// (cost) sum between j + 1, i do not exceed a constant shelfWidth.
// Now how to compute max_(k \in [j + 1, i])(height[k]) in amortized O(1) time?
// Access j as i-1, i-2, i-3, ... manner. In this manner, we update max_(k \in
// [j + 1, i])(height[k]) only once per step using height[j + 1], max_(k in [j +
// 2, i])(height[k]). Also we can record sumWidth with O(1) time.
