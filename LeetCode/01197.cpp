class Solution {
public:
    int dir[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    struct Point {
        int x, y;
        Point(int x, int y) : x(x), y(y) {}
        Point() : x(0), y(0) {}
        bool operator==(const Point &other) const {
            return x == other.x && y == other.y;
        }
        bool operator<(const Point &other) const {
            return x < other.x || (x == other.x && y < other.y);
        }
        int dist_max(const Point &other) const {
            return max(abs(x - other.x), abs(y - other.y));
        }
        int dist_min(const Point &other) const {
            return min(abs(x - other.x), abs(y - other.y));
        }
    };
    int minKnightMoves(int x, int y) {
        /*set<Point> visited_points;
        if (x == 0 && y == 0) return 0;
        Point aim {x, y};
        using ppi = pair<Point, int>;
        queue<ppi> visited_log;
        visited_log.push({{0, 0}, 0});
        while(!visited_log.empty()) {
            auto [pt, dist] = visited_log.front();
            visited_log.pop();
            for(int i=0; i<8; i++) {
                Point next_pt {pt.x + dir[i][0], pt.y + dir[i][1]};
                if (next_pt == aim) return dist + 1;
                if (visited_points.find(next_pt) != visited_points.end()) continue;
                if (next_pt.dist_max(aim) > pt.dist_max(aim)) continue;
                if (next_pt.dist_min(aim) > pt.dist_min(aim) && next_pt.dist_min(aim) >= 3) continue;
                visited_log.push({next_pt, dist + 1});
            }
        }
        return -1;
        */
        return f(x, y);
    }
    int f( int x , int y )
    {
        if (x < 0 || y < 0) {
            return f(abs(x), abs(y));
        }
        if (x < y) {
            return f(y, x);
        }
        if (x == 1 && y == 0) return 3;
        if (x == 2 && y == 2) return 4;
        int delta = x - y;
        if (y > delta) {
            return (int) (delta - 2 * floor((float) (delta - y) / 3));
        } else {
            return (int) (delta - 2 * floor((delta - y) / 4));
        }
    }
};
