class Solution {
public:
  int cost(int x, int y) {
    if (x == 26)
      return 0;
    return abs(x / 6 - y / 6) + abs(x % 6 - y % 6);
  }
  int minimumDistance(string word) {
    // 3D dp.
    /*
    https://leetcode.com/discuss/interview-question/456785/google-onsite-two-finger-typing
    I think that this can be done by using DP.
    Suppose we have dp[x][y][z] where x represents position our first hand and y
    represents position of second hand and z represents current index. This
    value contains the "remaining minimum cost". So dp[x][y][z]=min(distance
    from x to S[z] + dp[S[z]][y][z+1],distance from y to S[z] +
    dp[x][S[z]][z+1]), where S is the given string. Why? Since: first, x will
    move to S[z] from x at the next index; or y will move to S[z] from y at the
    next index. Base case : dp[x][y][z]=0 when z = length of string. One more
    thing: Since both finger starts at the out of the keyboard, we have to
    return dp[26][26][0]. When x or y equals to 26, cost must be 0. In the dp
    equation, rhs doesn't contain dp[26][26][z] form, so this doesn't break the
    optimal structure. Complexity will be O(27 * 27 * N), where N will be the
    size of the string.
    */
    /* Fix one side's next button and assign that dp value to the previous
     * button. Moving cost follows like below.*/
    int len = word.length();
    vector<vector<vector<int>>> dp(
        27, vector<vector<int>>(27, vector<int>(len + 1, 0)));
    for (int z = len - 1; z >= 0; z--) {
      for (int x = 0; x <= 26; x++) {
        for (int y = 0; y <= 26; y++) {
          if (z > 0 && x == 26 && y == 26)
            dp[x][y][z] = 300 * 26;
          dp[x][y][z] = min(cost(x, (int)(word[z] - 'A')) +
                                dp[(int)(word[z] - 'A')][y][z + 1],
                            cost(y, (int)(word[z] - 'A')) +
                                dp[x][(int)(word[z] - 'A')][z + 1]);
        }
      }
    }
    return dp[26][26][0];
  }
};
