class Solution {
public:
  vector<int> assignBikes(vector<vector<int>> &workers,
                          vector<vector<int>> &bikes) {
    /* Sol) Use priority queue to save distances between each worker and bike.
    If the printed out (worker_index, bike_index) is a valid one (that is,
    worker is not assigned; bike is not assigned), assign that bike. Repeat this
    until there are no available workers.
    */
    /* What is the data type of the instance that should be inserted?
    (worker_index, bike_index, distance).
    We can generate this by nm.
    Priority queue works in nmlog(nm) time.
    Advanced: can we manage the main pq's size up to n? It's possible, But the
    problem is, this method also works in nmlog(m).
    */
    using piii = pair<int, pair<int, int>>; // Distance, worker, bike.
    auto piii_comp_greater = [](const piii &a, const piii &b) {
      if (a.first > b.first)
        return true;
      if (a.first < b.first)
        return false;
      if (a.second.first > b.second.first)
        return true;
      if (a.second.first < b.second.first)
        return false;
      if (a.second.second > b.second.second)
        return true;
      return false;
    };
    auto manhattan = [](const vector<int> &w, const vector<int> &b) {
      return abs(w[0] - b[0]) + abs(w[1] - b[1]);
    };
    using pq_piii =
        priority_queue<piii, vector<piii>, decltype(piii_comp_greater)>;
    pq_piii pq(piii_comp_greater);
    vector<pq_piii> worker_priority(workers.size(), pq_piii(piii_comp_greater));
    vector<bool> bike_available(bikes.size(), true);
    vector<bool> worker_available(workers.size(), true);
    int available_workers = workers.size();

    int workers_len = workers.size(), bikes_len = bikes.size();
    for (int i = 0; i < workers_len; i++) {
      for (int j = 0; j < bikes_len; j++) {
        int dist = manhattan(workers[i], bikes[j]);
        worker_priority[i].push({dist, {i, j}});
      }
      piii worker_top = worker_priority[i].top();
      worker_priority[i].pop();
      pq.push(worker_top);
    }
    vector<int> assigned_bikes(workers_len, -1);
    while (available_workers > 0) {
      piii pq_top = pq.top();
      pq.pop();
      if (worker_available[pq_top.second.first] &&
          bike_available[pq_top.second.second]) {
        worker_available[pq_top.second.first] = false;
        bike_available[pq_top.second.second] = false;
        available_workers -= 1;
        assigned_bikes[pq_top.second.first] = pq_top.second.second;
      } else {
        // Since each worker can be inserted at most once, we don't have to do
        // any other things than just take the new bike.
        piii worker_top = worker_priority[pq_top.second.first].top();
        worker_priority[pq_top.second.first].pop();
        pq.push(worker_top);
      }
    }
    return assigned_bikes;
  }
};
