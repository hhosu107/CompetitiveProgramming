class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    int min_area = 2000000000;
    map<int, vector<int>> xs, ys;
    for (vector<int> p : points) {
      xs[p[0]].push_back(p[1]);
      ys[p[1]].push_back(p[0]);
    }
    for (map<int, vector<int>>::iterator it = xs.begin(); it != xs.end();
         it++) {
      sort(it->second.begin(), it->second.end());
    }
    for (map<int, vector<int>>::iterator it = ys.begin(); it != ys.end();
         it++) {
      sort(it->second.begin(), it->second.end());
    }
    for (map<int, vector<int>>::iterator it = xs.begin();
         next(it, 1) != xs.end(); it++) {
      int x_lower = it->first;
      for (int i = 0; i < it->second.size() - 1; i++) {
        for (int j = i + 1; j < it->second.size(); j++) {
          // x fixed, two ys given. Now we want to find: in ys, retrieve
          // ys1.value, ys2.value, and find the smallest common value.
          vector<int> y_lower_xs = ys[it->second[i]];
          vector<int> y_upper_xs = ys[it->second[j]];
          vector<int>::iterator iter_lower =
              lower_bound(y_lower_xs.begin(), y_lower_xs.end(), x_lower);
          vector<int>::iterator iter_upper =
              lower_bound(y_upper_xs.begin(), y_upper_xs.end(), x_lower);
          iter_lower = next(iter_lower, 1);
          iter_upper = next(iter_upper, 1);
          while (iter_lower != y_lower_xs.end() &&
                 iter_upper != y_upper_xs.end()) {
            if (y_lower_xs[iter_lower - y_lower_xs.begin()] ==
                y_upper_xs[iter_upper - y_upper_xs.begin()]) {
              int x_upper = y_lower_xs[iter_lower - y_lower_xs.begin()];
              min_area = min(min_area, (it->second[j] - it->second[i]) *
                                           (x_upper - x_lower));
              break;
            } else if (y_lower_xs[iter_lower - y_lower_xs.begin()] <
                       y_upper_xs[iter_upper - y_upper_xs.begin()]) {
              iter_lower = next(iter_lower, 1);
            } else
              iter_upper = next(iter_upper, 1);
          }
        }
      }
    }
    return (min_area == 2000000000 ? 0 : min_area);
  }
};
