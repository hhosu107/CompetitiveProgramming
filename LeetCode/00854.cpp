class Solution {
public:
  long long int string_hash(string s1) {
    long long int hash_val = 0;
    for (char c : s1) {
      hash_val = 8 * hash_val + (long long int)((int)(c - 'a'));
    }
    return hash_val;
  }
  long long int position_hash(int len, int p, long long int source_hash) {
    return (source_hash >> (3 * (len - p - 1))) % 8LL;
  }
  long long int converted_hash(int len, int p1, int p2,
                               long long int source_hash) {
    long long int source_p1 = position_hash(len, p1, source_hash);
    long long int source_p2 = position_hash(len, p2, source_hash);
    source_hash -= (source_p1 << (3 * (len - p1 - 1)));
    source_hash -= (source_p2 << (3 * (len - p2 - 1)));
    source_hash += (source_p1 << (3 * (len - p2 - 1)));
    source_hash += (source_p2 << (3 * (len - p1 - 1)));
    return source_hash;
  }
  bool convertible(int len, int p1, int p2, long long int source_hash,
                   long long int target_hash) {
    long long int source_p1 = position_hash(len, p1, source_hash);
    long long int source_p2 = position_hash(len, p2, source_hash);
    long long int target_p1 = position_hash(len, p1, target_hash);
    long long int target_p2 = position_hash(len, p2, target_hash);
    if (source_p1 == source_p2 || target_p1 == target_p2)
      return false;
    if (source_p1 == target_p1 && source_p2 == target_p2)
      return false;
    if (source_p1 == target_p2 || source_p2 == target_p1)
      return true;
    return false;
  }
  /*
  int kSimilarity(string s1, string s2) {
      // Sol) Use map for hashset. States: max 8^20, but much more under.
      // Edge 가지치기: current string, target string이 있을 때, current
  string의 두 포지션을 바꿨을 때 어느 한 쪽이 target string의 한 쪽과 일치애햐만
  convert 가능. if (s1 == s2) return 0; using ll = long long; using pli =
  pair<ll, int>; int len = s1.length(); long long int s1_hash = string_hash(s1);
      long long int s2_hash = string_hash(s2);
      unordered_set<ll> visited_hashes;
      queue<pli> hash_dist;
      hash_dist.push({s1_hash, 0});
      visited_hashes.insert(s1_hash);
      while(!hash_dist.empty()) {
          pli next_pair = hash_dist.front();
          hash_dist.pop();
          for (int i=0; i<len - 1; i++) {
              for(int j=i+1; j<len; j++) {
                  bool is_convertible = convertible(len, i, j, next_pair.first,
  s2_hash); if (!is_convertible) continue; ll next_hash = converted_hash(len, i,
  j, next_pair.first); if (next_hash == s2_hash) return next_pair.second + 1; if
  (visited_hashes.find(next_hash) != visited_hashes.end()) continue;
                  visited_hashes.insert(next_hash);
                  hash_dist.push({next_hash, next_pair.second + 1});
              }
          }
      }
      return -1;
  }
  */
  int kSimilarity(string A, string B) {

    // if A == B return 0
    if (A == B) {
      return 0;
    }
    int i = 0;

    // find the first char we need to swap
    while (A[i] == B[i]) {
      i++;
    }

    vector<int> matches;
    for (int j = i + 1; j < A.size(); j++) {
      // we skip when A[j]==B[j] in this case, we don't need to swap
      // or A[j] != B[i] in this case, swap(A[i], A[j]) don't have meaning
      if (A[j] != B[j] && A[j] == B[i]) {
        // push all satisfactory j into vector
        matches.push_back(j);

        // if A[i] == B[j],
        // when we swap(A[i], A[j]) it could help to max the benefit
        // because we match two chars in a single swap, it is the max benefit we
        // could get from a single swap) it must be the optimal solution, we
        // just need to return the res and skip the rest of the code and don't
        // need to swap back since we won't trace back.

        // I think it is the most genius part of the code, which helps to
        // improve the performance significantly. the code could also work
        // without this part, but the runtime is 826 ms, which is much slower
        // than 16ms

        if (A[i] == B[j]) {
          swap(A[i], A[j]);
          return 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1));
        }
      }
    }

    // best couldn't be more than A.size()
    int best = A.size();

    // for each match, we would swap it and call the recursive
    // find the best solution
    for (auto match : matches) {
      swap(A[i], A[match]);
      best = min(best, 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1)));
      swap(A[i], A[match]);
    }
    return best;
  }
};
// The problem I met:
// 나는 hash+가지치기 써서 풀려고 했으나, TLE 받음.
// 아이디어는, 애초에 이 앞까지의 string이 일치한다면 뒤쪽에서 일치하는 부분의
// index를 참조할 필요가 없다는 것.
// 즉 현재 가지고 있는 substring x, y 중 x[0:i-1] == y[0:i-1]이고 x[i] !=
// y[i]라면, x[j] == y[i]이고 x[j] != y[j]인 모든 j (미래의 j를 참조하여 현재의
// i를 때우는 것이므로 조건이 이렇게 되어야 한다.) 에 대해 x[i]와 x[j]를 swap한
// 다음 x[i+1:]과 y[i+1:]에서의 최소 교환 횟수를 세어 최소값을 반환하면 된다.
// 다만, 만약 어떤 j(최소값)에 대해 x[i] == y[j]마저 성립한다면, 이 둘을
// 바꿔버리면 미래의 어떤 index j까지 즉시 고정 가능하므로 위에서 취하던
// 후보들을 볼 필요조차 없이 이게 optimal하다. 따라서 둘을 교환한 다음 x[i+1:]과
// y[i+1:]만 보도록 fast return해버리면 된다.
