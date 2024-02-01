class Solution {
public:
  unordered_map<int, int> f;
  int islands = 0;
  int removeStones(
      vector<vector<int>>
          &stones) { // Equivallently, we have to find the number of connected
                     // components, where both stones are originally connected
                     // if they share the same column or the same row.
    for (int i = 0; i < stones.size(); ++i)
      uni(stones[i][0],
          ~stones[i]
                 [1]); // tilde: 2's complement; thus stones[x][0] !=
                       // stones[y][1] for all x and y. Union means that every
                       // stones on stones[i][0]'th row and stones[i][1]'th
                       // column are in the same island (connects them)
    return stones.size() - islands;
  }

  int find(int x) {
    if (!f.count(x))
      f[x] = x, islands++; // There is a stone with index x (if positive, on a
                           // row; if negative, on a col)
    if (x != f[x])
      f[x] = find(f[x]); // find the root
    return f[x];
  }

  void uni(int x, int y) {
    x = find(x), y = find(y); // find representative of each row/col.
    if (x != y)
      f[x] = y,
      islands--; // connect the row to the column and decrease islands by 1.
  }
};
