class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, down = matrix.size(), left = 0, right = matrix[0].size();
        int dir = 0;
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> spiral;
        while(top < down && left < right) {
            if (dir == 0) {
                for(int j=left; j<right; j++) {
                    spiral.push_back(matrix[top][j]);
                }
                top += 1;
            } else if (dir == 1) {
                for(int i=top; i<down; i++) {
                    spiral.push_back(matrix[i][right-1]);
                }
                right -= 1;
            } else if (dir == 2) {
                for(int j=right - 1; j>=left; j--) {
                    spiral.push_back(matrix[down - 1][j]);
                }
                down -= 1;
            } else if (dir == 3) {
                for(int i=down - 1; i>=top; i--) {
                    spiral.push_back(matrix[i][left]);
                }
                left += 1;
            }
            dir = (dir + 1) % 4;
        }
        return spiral;
    }
};
