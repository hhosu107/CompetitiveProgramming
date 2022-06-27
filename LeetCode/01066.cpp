struct costBike {
    int cost;
    int num_users;
    int bike_bitset;
    costBike(int c, int n, int b) : cost(c), num_users(n), bike_bitset(b) {}
    costBike() : cost(0), num_users(0), bike_bitset(0) {}
};

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        auto dist = [&](const int &i, const int &j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };
        auto costComp = [](const costBike &a, const costBike &b) {
            if (a.cost != b.cost) return a.cost > b.cost;
            if (a.num_users != b.num_users) return a.num_users < b.num_users;
            if (a.bike_bitset != b.bike_bitset) return a.bike_bitset > b.bike_bitset;
            return false;
        };
        priority_queue<costBike, vector<costBike>, decltype(costComp)> pq(costComp);
        set<pair<int, int>> user_bike_seen = set<pair<int, int>>();
        pq.push(costBike());
        while (true) {
            // auto [cost, num_users, bike_bitset] = pq.top();
            costBike c = pq.top();
            pq.pop();
            if (user_bike_seen.find({c.num_users, c.bike_bitset}) != user_bike_seen.end()) continue;
            user_bike_seen.insert({c.num_users, c.bike_bitset});
            if (c.num_users == workers.size()) {
                return c.cost;
            }
            for (int j=0; j<bikes.size(); j++) {
                if ((c.bike_bitset & (1 << j)) == 0) {
                    pq.push({c.cost + dist(c.num_users, j), c.num_users + 1, c.bike_bitset | (1 << j)});
                }
            }
        }
        return 2000 * workers.size(); // Unreachable
    }
};
