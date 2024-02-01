class Solution {
public:
  vector<int> diStringMatch(string s) {
    int len = s.length();
    long long int unused_sum =
        (long long int)len * (long long int)(len + 1) / (long long int)2;
    vector<int> perm(len + 1, 0);
    int dec = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == 'D')
        dec++;
    }
    perm[0] = dec;
    int inc = dec + 1;
    dec--;
    int max_start = len, min_start = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == 'I') {
        perm[i + 1] = inc;
        inc++;
      } else {
        perm[i + 1] = dec;
        dec--;
      }
    }
    return perm;
  }
};
