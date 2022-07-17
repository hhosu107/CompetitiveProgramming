#include<vector>
using namespace std;
class Solution {
public:
    int rows, cols;
    vector<vector<int>> grid;
    int path_count;
    void backtrack(int row, int col, int remain) {
        if (grid[row][col] == 2 && remain == 1) {
            path_count += 1;
            return;
        }
        // Save grid state; mark grid as visited by writing grid[row][col] = -4;
        // unmark grid as visited after backtracking by writing grid[row][col] =
        // temp;
        int temp = grid[row][col];
        grid[row][col] = -4;
        remain -= 1;

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0; i<4; i++) {
            int nx = row + dirs[i][0];
            int ny = col + dirs[i][1];
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
            if (grid[nx][ny] < 0) // either obstacle or visited
                continue;
            backtrack(nx, ny, remain);
        }
        // unmark
        grid[row][col] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int non_obstacles = 0, start_row = 0, start_col = 0;
        rows = grid.size();
        cols = grid[0].size();
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++) {
                int cell = grid[r][c];
                if (cell >= 0)
                    non_obstacles += 1;
                if (cell == 1) {
                    start_row = r;
                    start_col = c;
                }
            }
        }
        path_count = 0;
        this->grid = vector<vector<int>>(grid);
        backtrack(start_row, start_col, non_obstacles);
        return path_count;
    }
};
