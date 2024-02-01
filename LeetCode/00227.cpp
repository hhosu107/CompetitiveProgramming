/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
  int size;
  unordered_map<pair<int, int>, bool> cache;
  bool knows_cover(int a, int b) {
    if (cache.find(make_pair(a, b)) != cache.end()) {
      return cache[make_pair(a, b)];
    }
    return knows(a, b);
  }
  int findCelebrity(int n) {
    size = n;
    cache = unordered_map<pair<int, int>, bool>();
    int celebrityCandidate = 0;
    for (int i = 0; i < n; i++) {
      // if this returns true, then current celebrityCandidate is not a
      // celebrity.
      // if this returns false, since celebrity must be known by all
      // others, i is not a celebrity.
      // Thus, except i == 0, we decrease candidate of celebrity by 1 for
      // each step, which means we excluded n - 1 celebrities.
      if (knows_cover(celebrityCandidate, i)) {
        celebrityCandidate = i;
      }
    }
    // This one is the only one who could be celebrity.
    if (isCelebrity(celebrityCandidate))
      return celebrityCandidate;
    return -1;
  }
  bool isCelebrity(int i) {
    for (int j = 0; j < size; j++) {
      if (i == j)
        continue;
      if (knows_cover(i, j) || !knows_cover(j, i))
        return false;
    }
    return true;
  }
};
