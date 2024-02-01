class SelectIdx {
public:
  vector<int> indices;
  int size;
  int sum;
  SelectIdx(int n) {
    size = n;
    indices = vector<int>(n);
    sum = 0;
  }
  SelectIdx(int n, vector<vector<int>> &mat) : SelectIdx(n) {
    for (vector<int> row : mat) {
      sum += row[0];
    }
  }
  bool increase_idx(int r, vector<vector<int>> &mat) {
    if (mat[0].size() == indices[r] + 1)
      return false;
    sum -= mat[r][indices[r]];
    indices[r]++;
    sum += mat[r][indices[r]];
    return true;
  }
  bool decrease_idx(int r, vector<vector<int>> &mat) {
    if (0 == indices[r])
      return false;
    sum -= mat[r][indices[r]];
    indices[r]--;
    sum += mat[r][indices[r]];
    return true;
  }
  SelectIdx &operator=(const SelectIdx &o) {
    size = o.size;
    sum = o.sum;
    indices = vector<int>(o.indices);
    return *this;
  }
  bool operator<(const SelectIdx &o) const { return sum < o.sum; }
  bool operator>(const SelectIdx &o) const { return sum > o.sum; }
};

class Solution {
public:
  string select_idx_to_string(SelectIdx &x) {
    string hash_val = "";
    for (int i : x.indices) {
      hash_val += to_string(i) + "-";
    }
    return hash_val;
  }
  int kthSmallest(vector<vector<int>> &mat, int k) {
    unordered_set<string> visited_elements;
    int n = mat.size();
    priority_queue<SelectIdx, vector<SelectIdx>, greater<SelectIdx>> pq;
    SelectIdx init_indices(n, mat);
    pq.push(init_indices);
    visited_elements.insert(select_idx_to_string(init_indices));
    int left_selections = k;
    while (!pq.empty()) {
      SelectIdx curr = pq.top();
      pq.pop();
      if (left_selections == 1) {
        return curr.sum;
      }
      for (int i = 0; i < n; i++) {
        bool increased = curr.increase_idx(i, mat);
        if (!increased)
          continue;
        string hash_val = select_idx_to_string(curr);
        if (visited_elements.find(hash_val) == visited_elements.end()) {
          pq.push(curr);
          visited_elements.insert(hash_val);
        }
        curr.decrease_idx(i, mat);
      }
      left_selections--;
    }
    int end_sum = 0;
    for (int i = 0; i < n; i++)
      end_sum += mat[i][mat[0].size() - 1];
    return end_sum;
  }
  // easiest solution: pq.
  // for each item, we have at most m options to add.
  // thus, there will be at most k * m different element in the pq when we
  // finish the job.
  // // Time complexity: O(k * m * log(km)).
  // // 문제점: 쓸데없이 너무 많은 정보들을 저장하고 있다.
  // 1) hash_val을 따로 만들어서 visited compare를 O(k * m)에 하려고 했던 것.
  // 저건 필요없다. vector<int> object는 compare 가능한 object이기 때문에.
  // 그리고 pair<int, vector<int>> 역시 compare 가능한 object이다.
  // 그렇게 compare해버려도 (set으로 관리), comparing time complexity가 O(k *
  // m * log(k * m))이므로 time complexity에 지장을 주지 않는다.
  // 오히려, hash value 만든다고 매 번 길이 n만큼의 string을 만들어버려서,
  // 새로운 time complexity O(k * m * n)을 만들고 말았다.
  // 그냥 pair를 쓰는 게 머리가 편한 것이었다.. 그리고 sum 역시 pair의 첫 번째
  // element로 즉시 따라다닐 수 있고.
};
