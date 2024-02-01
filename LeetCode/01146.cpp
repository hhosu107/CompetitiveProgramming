using pii = pair<int, int>;
class SnapshotArray {
public:
  vector<vector<int>> snapshot_timing;
  vector<vector<int>> snapshot_value;
  int num_snapshots;
  queue<pii> caught_values;
  SnapshotArray(int length) {
    snapshot_timing = vector<vector<int>>(length, vector<int>(1, -1));
    snapshot_value = vector<vector<int>>(length, vector<int>(1, 0));
    caught_values = queue<pii>();
    num_snapshots = 0;
  }

  void set(int index, int val) { caught_values.push({index, val}); }

  int snap() {
    while (!caught_values.empty()) {
      pii head = caught_values.front();
      caught_values.pop();
      snapshot_timing[head.first].push_back(num_snapshots);
      snapshot_value[head.first].push_back(head.second);
    }
    num_snapshots++;
    return num_snapshots - 1;
  }

  int get(int index, int snap_id) {
    auto snap_idx = upper_bound(snapshot_timing[index].begin(),
                                snapshot_timing[index].end(), snap_id);
    snap_idx--;
    cout << snap_idx - snapshot_timing[index].begin() << endl;
    return snapshot_value[index]
                         [(int)(snap_idx - snapshot_timing[index].begin())];
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

/* After mock session...
 * vector<map<int, int>> is much better for this problem.
 * If we insert same key in the map, it just updates the value, so the lower
 * bound for snapshot just works for finding the latest value.
 * whereas my implementation generates duplicated snapshot timings, which then
 * requires the previous index of upper bound.
 * Furthermore, to maintain that snapshot indices, I had to update another
 * vector to contain the key. This is just a waste.
 */
