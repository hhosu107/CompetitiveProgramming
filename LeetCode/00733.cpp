class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> floodfilled_image(image);
        int affected_cell = image[sr][sc];
        if (color == affected_cell) return floodfilled_image;
        // Perform bfs where edge = cells adjacent to the current cell with value affected_cell.
        queue<pair<int, int>> cells;
        floodfilled_image[sr][sc] = color;
        cells.push({sr, sc});
        while(!cells.empty()) {
            pair<int, int> curr = cells.front();
            cells.pop();
            for(int i=0; i<4; i++) {
                int dx = curr.first + dir[i][0];
                int dy = curr.second + dir[i][1];
                if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                if (floodfilled_image[dx][dy] != affected_cell) continue;
                floodfilled_image[dx][dy] = color;
                cells.push({dx, dy});
            }
        }
        return floodfilled_image;
    }
};
