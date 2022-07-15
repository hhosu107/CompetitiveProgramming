using pii = pair<int, int>;
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int islands = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '0') continue;
                queue<pii> q;
                visited[i][j] = true;
                islands += 1;
                q.push({i, j});
                while(!q.empty()) {
                    pii curr = q.front();
                    q.pop();
                    for(int i=0; i<4; i++) {
                        int nx = curr.first + dd[i][0];
                        int ny = curr.second + dd[i][1];
                        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
                        if (grid[nx][ny] == '1' && !visited[nx][ny]) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        return islands;
    }
};
