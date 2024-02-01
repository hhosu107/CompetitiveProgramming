class Solution {
public:
  void dfs(int visiting_index, vector<vector<int>> &starting_edges,
           vector<bool> &reachable) {
    if (reachable[visiting_index])
      return;
    reachable[visiting_index] = true;
    for (int nxt : starting_edges[visiting_index]) {
      dfs(nxt, starting_edges, reachable);
    }
  }

  bool dfs_cycle(int visiting_index, vector<vector<int>> &starting_edges,
                 vector<bool> &reachable, set<int> &visited_indices,
                 vector<bool> &self_cycle) {
    if (self_cycle[visiting_index])
      return true;
    if (reachable[visiting_index])
      return false;
    reachable[visiting_index] = true;
    for (int nxt : starting_edges[visiting_index]) {
      if (visited_indices.size() > 0 &&
          visited_indices.find(nxt) != visited_indices.end()) {
        return true;
      }
      visited_indices.insert(visiting_index);
      bool sub_found = dfs_cycle(nxt, starting_edges, reachable,
                                 visited_indices, self_cycle);
      visited_indices.erase(visiting_index);
      if (sub_found)
        return true;
    }
    return false;
  }

  bool leadsToDestination(int n, vector<vector<int>> &edges, int source,
                          int destination) {
    /* We have to check several things.
    1. Are there any nodes other than destination that is reachable from source
    with no outgoing edge?
    2. Is the destination node reachable from source and there is no outgoing
    edge from destination?
    3. Are there no cycle in the directed graph that is reachable from the
    source? Checking 2 is trivial. Checking 1 is done by simple dfs from source:
    If there is a node with no outgoing edge, we are done. Checking 3 is not so
    simple, but also can be done by dfs with saving visited nodes with set. If
    there is a cycle, if that cycle is not included on the path to the
    destination, it is equal to think that nodes as one terminal node. If that
    cycle is included on the path to the destination, that makes the possibility
    to go the destination indefinitely. If we finish all checks, we are done.
    */
    int edges_len = edges.size();
    vector<vector<int>> starting_edges(n, vector<int>(0));
    vector<bool> self_cycle(n, false);
    for (auto e : edges) {
      starting_edges[e[0]].push_back(e[1]);
      if (e[0] == e[1]) {
        self_cycle[e[0]] = true;
      }
    }
    if (starting_edges[destination].size() > 0)
      return false;
    vector<bool> reachable(n, false);
    dfs(source, starting_edges, reachable);
    if (!reachable[destination])
      return false;
    for (int i = 0; i < n; i++) {
      if (i != source && i != destination && reachable[i] &&
          starting_edges[i].size() == 0) {
        return false;
      }
    }
    /* Now let's check 3. */
    vector<bool> reachable_when_cycle(n, false);
    set<int> visited_indices = set<int>();
    bool cycle_detection =
        dfs_cycle(source, starting_edges, reachable_when_cycle, visited_indices,
                  self_cycle);
    return !cycle_detection;
  }
};
