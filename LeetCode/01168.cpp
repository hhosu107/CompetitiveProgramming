class Solution {
public:
  int minCostToSupplyWater(int n, vector<int> &wells,
                           vector<vector<int>> &pipes) {
    // Sol) construct minimum spanning tree, but there are some mutations.
    // for each insertion, we either put a well or put a pipe.
    // make wells as [idx, idx, cost] pipe.
    // sort pipes with cost increasing order. do find for them, and if they are
    // in the different representatives, add that pipe.
    auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.first > b.first;
    }; // for minheap.
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < n + 1; i++)
      graph[i] = vector<pair<int, int>>();
    for (int i = 0; i < wells.size(); i++) {
      pair<int, int> virtualEdgeToWell(wells[i], i + 1);
      graph[0].push_back(virtualEdgeToWell);
      pq.push(virtualEdgeToWell);
    }
    for (vector<int> p : pipes) {
      int house1 = p[0];
      int house2 = p[1];
      int cost = p[2];
      graph[house1].emplace_back(cost, house2);
      graph[house2].emplace_back(cost, house1);
    }
    unordered_set<int> mst;
    mst.insert(0);
    int total_cost = 0;
    while (mst.size() < n + 1) {
      pair<int, int> edge = pq.top();
      pq.pop();
      int cost = edge.first;
      int next_house = edge.second;
      if (mst.find(next_house) != mst.end()) {
        continue;
      }
      total_cost += cost;
      mst.insert(next_house);
      for (pair<int, int> neighbors : graph[next_house]) {
        if (mst.find(neighbors.second) == mst.end())
          pq.push(neighbors);
      }
    }
    return total_cost;
  }
};
// Since the well is the virtual node that is already connected with water
// source, add 0 as the new house that already contains water. If every house is
// connected with node 0, we are done. construct [0, house_i, wells[i]] edge for
// that.
