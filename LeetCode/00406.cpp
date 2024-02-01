clas Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> & people) {
    // Could this be done in people.size()^2?
    auto comp = [&people](const vector<int> &a, const vector<int> &b) {
      return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    };
    sort(people.begin(), people.end(), comp);
    // Then, we place heavier people first and lighter people second.
    // if we succeed to find each place to insert, each insertion doesn't change
    // the relative greater or equal amount of people.
    vector<vector<int>> reconstructed;
    int max_val = people[0][0];
    for (vector<int> s : people) {
      if (s[0] == max_val)
        reconstructed.push_back(s);
      else {
        reconstructed.insert(reconstructed.begin() + s[1], s);
      }
    }
    return reconstructed;
  }
}
