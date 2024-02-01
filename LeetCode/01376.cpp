class Solution {
public:
  int bfs(vector<vector<int>> &edges, vector<int> &informTime, int headID) {
    using pii = pair<int, int>;
    queue<pii> emp_inform;
    emp_inform.push({headID, 0});
    int max_inform_time = 0;
    while (!emp_inform.empty()) {
      pii curr_inform = emp_inform.front();
      emp_inform.pop();
      max_inform_time = max(max_inform_time, curr_inform.second);
      for (int next_emp : edges[curr_inform.first]) {
        emp_inform.push(
            {next_emp, curr_inform.second + informTime[curr_inform.first]});
      }
    }
    return max_inform_time;
  }
  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    vector<vector<int>> inform_edges(n, vector<int>());
    for (int i = 0; i < n; i++) {
      if (headID == i)
        continue;
      inform_edges[manager[i]].push_back(i);
    }
    return bfs(inform_edges, informTime, headID);
  }
};
