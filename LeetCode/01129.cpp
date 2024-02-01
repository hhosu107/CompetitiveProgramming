class ColoredEdge {
public:
  bool color;
  int end;
  ColoredEdge() : color(false), end(-1) {}
  ColoredEdge(bool c, int e) : color(c), end(e) {}
};

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                       vector<vector<int>> &blueEdges) {
    unordered_map<int, vector<ColoredEdge>> colored_edges;
    vector<int> dist(2 * n, -1);
    dist[0] = 0;
    dist[n] = 0;
    for (vector<int> re : redEdges) {
      if (colored_edges.count(re[0]) == 0) {
        colored_edges[re[0]] = vector<ColoredEdge>();
      }
      colored_edges[re[0]].push_back(ColoredEdge(true, re[1] + n));
    }
    for (vector<int> bl : blueEdges) {
      if (colored_edges.count(bl[0] + n) == 0) {
        colored_edges[bl[0] + n] = vector<ColoredEdge>();
      }
      colored_edges[bl[0] + n].push_back(ColoredEdge(false, bl[1]));
    }
    queue<int> visits;
    visits.push(0);
    visits.push(n);
    while (!visits.empty()) {
      int curr = visits.front();
      visits.pop();
      vector<ColoredEdge> next_nodes = colored_edges[curr];
      for (ColoredEdge next : next_nodes) {
        if (dist[next.end] != -1)
          continue;
        dist[next.end] = dist[curr] + 1;
        visits.push(next.end);
      }
    }
    vector<int> min_dist(n, -1);
    min_dist[0] = 0;
    for (int i = 1; i < n; i++) {
      if (dist[i] != -1 && dist[i + n] != -1)
        min_dist[i] = min(dist[i], dist[i + n]);
      else if (dist[i] != -1)
        min_dist[i] = dist[i];
      else if (dist[i + n] != -1)
        min_dist[i] = dist[i + n];
    }
    return min_dist;
  }
};
