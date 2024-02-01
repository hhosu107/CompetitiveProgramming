class FirstUnique {
public:
  unordered_map<int, int> num_count;
  queue<int> lazy_queue;
  FirstUnique(vector<int> &nums) {
    num_count = unordered_map<int, int>();
    lazy_queue = queue<int>();
    for (int n : nums) {
      if (num_count.find(n) == num_count.end())
        lazy_queue.push(n);
      num_count[n] += 1;
    }
  }

  int showFirstUnique() {
    while (!lazy_queue.empty() && num_count[lazy_queue.front()] > 1) {
      lazy_queue.pop();
    }
    if (lazy_queue.empty())
      return -1;
    return lazy_queue.front();
  }

  void add(int value) {
    if (num_count.find(value) == num_count.end())
      lazy_queue.push(value);
    num_count[value] += 1;
  }
};
