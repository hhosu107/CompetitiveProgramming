usin pds = pair<double, string>;
using psds = pair<string, pds>;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pds>> graph;
        for(int i=0; i<equations.size(); i++) {
            if (graph.count(equations[i][0]) == 0) {
                graph[equations[i][0]] = vector<pds>();
            }
            if (graph.count(equations[i][1]) == 0) {
                graph[equations[i][1]] = vector<pds>();
            }
            graph[equations[i][0]].push_back({values[i], equations[i][1]});
            graph[equations[i][1]].push_back({1.0f / values[i], equations[i][0]});
        }
        int ql = queries.size();
        vector<double> ret_values(ql, -1.0f);
        for(int i=0; i<ql; i++) {
            if (queries[i][0] == queries[i][1]) {
                if (graph.count(queries[i][0]) == 0) {
                    continue;
                } else {
                    ret_values[i] = 1.0f;
                    continue;
                }
            }
            if (graph.count(queries[i][0]) == 0 || graph.count(queries[i][1]) == 0) {
                continue;
            }
            set<string> visited_vars;
            queue<pds> curr_values;
            curr_values.push({1.0f, queries[i][0]});
            visited_vars.insert(queries[i][0]);
            while(!curr_values.empty()) {
                pds curr = curr_values.front();
                curr_values.pop();
                if (curr.second == queries[i][1]) {
                    ret_values[i] = curr.first;
                    break;
                }
                for (auto it=graph[curr.second].begin(); it!=graph[curr.second].end(); it++) {
                    if (visited_vars.find((*it).second) != visited_vars.end()) continue;
                    visited_vars.insert((*it).second);
                    curr_values.push({curr.first * (*it).first, (*it).second});
                }
            }
        }
        return ret_values;
        // Sol) Equation variables -> node,
        // Equation values -> edge wegiht.
        // Path weight = product of edge weight.
        // a -> b.
        // query에 identical string: 1) query has known variables. -> a / a = 1. 2) query has unknown variables. -> x / x -> -1.
        // query에 주어진 두 variable이 연결되어있지 않은 경우 -> -1.
        
    }
};
