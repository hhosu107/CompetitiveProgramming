#include<vector>
#include<functional>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class PointViolation {
public:
    int steps, x, y, v;
    PointViolation() : steps(0), x(0), y(0), v(0) {}
    PointViolation(int _s, int _x, int _y, int _v) : steps(_s), x(_x), y(_y), v(_v) {}
    bool operator==(const PointViolation& o) const {
        return (x == o.x && y == o.y && v == o.v);
    }
    string toString() const {
        return to_string(x) + " " + to_string(y) + " " + to_string(v);
    }
};

struct MyHash
{
	std::size_t operator()(PointViolation const& s) const noexcept
	{
        string s_string = s.toString();
        std::hash<string> str_hash;
        return str_hash(s_string);
	}
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // Sol) BFS, but with number of eliminations.
        int m = grid.size();
        int n = grid[0].size();
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        if (k >= m + n - 2) return m + n - 2; // just go down and go right.
        PointViolation pv{0, 0, 0, k};
        queue<PointViolation> q;
        unordered_set<PointViolation, MyHash> seen;
        q.push(pv);
        seen.insert(pv);
        while(!q.empty()) {
            PointViolation curr = q.front();
            q.pop();
            if (m - 1 == curr.x && n - 1 == curr.y)
                return curr.steps;
            for(int i=0; i<4; i++) {
                int nx = curr.x + dir[i][0];
                int ny = curr.y + dir[i][1];
                if (0 > nx || m <= nx || 0 > ny || n <= ny) continue;
                int next_violation = curr.v - grid[nx][ny];
                PointViolation npv{curr.steps + 1, nx, ny, next_violation};
                if (next_violation >= 0 && seen.find(npv) == seen.end()) {
                    if (nx == m - 1 && ny == n - 1) {
                        return npv.steps;
                    }
                    seen.insert(npv);
                    q.push(npv);
                }
            }
        }
        return -1;
    }
};
