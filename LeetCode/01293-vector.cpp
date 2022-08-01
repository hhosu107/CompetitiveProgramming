#include<vector>
#include<queue>
#include<unordered_set>
#include<functional>
#include<string>
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
        /*
		std::size_t h1 = std::hash<std::int32_t>{}(s.x);
		std::size_t h2 = std::hash<std::int32_t>{}(s.y);
		std::size_t h12 = h1 ^ (h2 << 1); // or use boost::hash_combine (see Discussion)
        std::size_t h3 = std::hash<std::int32_t>{}(s.steps);
		std::size_t h4 = std::hash<std::int32_t>{}(s.v);
		std::size_t h34 = h3 ^ (h4 << 1); // or use boost::hash_combine (see Discussion)
        return h12 ^ (h34 << 1);
        */
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
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k + 1, k * (m * n + 1))));
        PointViolation pv{0, 0, 0, k};
        queue<PointViolation> q;
        dist[0][0][k] = 0;
        q.push(pv);
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
                PointViolation npv{dist[curr.x][curr.y][curr.v] + 1, nx, ny, next_violation};
                if (next_violation >= 0 && dist[nx][ny][next_violation] == k * (m * n + 1)) {
                    if (nx == m - 1 && ny == n - 1) {
                        return npv.steps;
                    }
                    dist[nx][ny][next_violation] = npv.steps;
                    q.push(npv);
                }
            }
        }
        return -1;
    }
};
