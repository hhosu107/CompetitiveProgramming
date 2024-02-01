struct TaskLeftAble {
  char task;
  int left_tasks;
  int able_timestamp;
  TaskLeftAble() : task(' '), left_tasks(0), able_timestamp(0) {}
  TaskLeftAble(char t, int l, int a)
      : task(t), left_tasks(l), able_timestamp(a) {}

  bool operator<(const TaskLeftAble &o) const {
    if (left_tasks != o.left_tasks)
      return left_tasks < o.left_tasks;
    if (able_timestamp != o.able_timestamp)
      return able_timestamp > o.able_timestamp;
    return (task > o.task);
  }
  TaskLeftAble operator=(const TaskLeftAble &o) {
    task = o.task;
    left_tasks = o.left_tasks;
    able_timestamp = o.able_timestamp;
    return *this;
  }
};

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> task_count;
    for (char t : tasks)
      task_count[t] += 1;
    priority_queue<TaskLeftAble> pq;
    queue<TaskLeftAble> waiting;
    for (const auto &[t, l] : task_count)
      pq.push(TaskLeftAble(t, l, 1));
    int unit_time = 0;
    while (!pq.empty()) {
      TaskLeftAble curr = pq.top();
      pq.pop();
      unit_time = max(unit_time + 1, curr.able_timestamp);
      if (curr.left_tasks > 1) {
        waiting.push(
            TaskLeftAble(curr.task, curr.left_tasks - 1, unit_time + n + 1));
      }
      if (!waiting.empty() &&
          (pq.empty() || unit_time + 1 >= waiting.front().able_timestamp)) {
        do {
          TaskLeftAble next = waiting.front();
          waiting.pop();
          pq.push(next);
        } while (!waiting.empty() &&
                 unit_time + 1 >= waiting.front().able_timestamp);
      }
    }
    return unit_time;
  }
};
