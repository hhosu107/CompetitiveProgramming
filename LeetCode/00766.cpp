class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        queue<int> row;
        for(int i=0; i<matrix[0].size(); i++) {
            row.push(matrix[matrix.size()-1][i]);
        }
        for(int i=matrix.size()-2; i>=0; i--) {
            row.pop();
            for(int j=0; j<matrix[0].size()-1; j++) {
                int row_head = row.front();
                row.pop();
                if (row_head != matrix[i][j])
                    return false;
                row.push(matrix[i][j]);
            }
            row.push(matrix[i][matrix[0].size()-1]);
        }
        return true;
    }
};
