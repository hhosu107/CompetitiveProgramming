#include<bits/stdc++.h>
/* Problem asks:
 * There are directed edges with 2 colors. There are also self edges and
 * parallel edges.
 * (Maybe we can make each edge unique, since this problem asks to find shortest
 * path.)
 * With altering colors of edges, find length of shortest path from node 0 to
 * each node(including node 0).
 * Idea: Split each node into 2, one with color 0 and one with color 1.
 * If there is a path from node 0 to node 1, then we can find the color it
 * started.
 * Thus we do 2 * (n - 1) times of bfs; 2 for each node (1 for color 0 and 1 for
 * color 1).
 */
using namespace std;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

    }
};
