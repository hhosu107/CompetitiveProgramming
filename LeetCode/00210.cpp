class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, int> in_edges;
        map<int, set<int>> out_edges;
        
        for(vector<int> p: prerequisites) {
            if (out_edges.count(p[0]) == 0) {
                out_edges[p[0]] = set<int>();
            }
            if (in_edges.count(p[0]) == 0) {
                in_edges[p[0]] = 0;
            }
            if (in_edges.count(p[1]) == 0) {
                in_edges[p[1]] = 0;
            }
            in_edges[p[0]] += 1;
            out_edges[p[1]].insert(p[0]);
        }
        queue<int> topological;
        vector<int> order;
        for(int i=0; i<numCourses; i++) {
            if (in_edges.count(i) == 0)
                order.push_back(i);
        }
        for(const auto &[s, t]: in_edges) {
            if (t == 0)
                topological.push(s);
        }
        int courses = numCourses - in_edges.size();
        while(!topological.empty()) {
            int c = topological.front();
            order.push_back(c);
            topological.pop();
            courses += 1;
            for (int p: out_edges[c]) {
                in_edges[p] -= 1;
                if (in_edges[p] == 0) {
                    topological.push(p);
                }
            }
        }
        return (numCourses == courses ? order : vector<int>());
    }
};
