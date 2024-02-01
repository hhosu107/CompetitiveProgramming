class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> freq(26);
    for (char t : tasks)
      freq[t - 'A']++;
    int freq_max = 0;
    for (int f : freq)
      freq_max = max(freq_max, f);
    int n_max = 0;
    for (int f : freq)
      if (f == freq_max)
        n_max++;
    return max(int(tasks.size()), (freq_max - 1) * (n + 1) + n_max);
  }
};
/*
Algorithm

The maximum number of tasks is 26. Let's allocate an array frequencies of 26
elements to keep the frequency of each task.

Iterate over the input array and store the frequency of task A at index 0, the
frequency of task B at index 1, etc.

Find the maximum frequency: f_max = max(frequencies).

Find the number of tasks which have the max frequency: n_max =
frequencies.count(f_max).

If the number of slots to use is defined by the most frequent task, it's equal
to (f_max - 1) * (n + 1) + n_max.

Otherwise, the number of slots to use is defined by the overall number of tasks:
len(tasks).

Return the maximum of these two: max(len(tasks), (f_max - 1) * (n + 1) + n_max).
*/
