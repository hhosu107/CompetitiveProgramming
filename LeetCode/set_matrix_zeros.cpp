#include<vector>
using namespace std;

/* In-place vector manipulation.
https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/
Idea: Use first row/column as a manipulation candidate.
For instance, if matrix[i][j] == 0, then for all k, l, matrix[k][j] = matrix[i][l] = 0, but if we do this for every i, j, then we get O(ROW * COL * (ROW + COL)) time complexity.
Not to do this, we have to save what row/column should be manipulated, but saving that outside of the matrix generates O(ROW + COL) space.
Thus, among rows and columns, without loss of generality, select the first row/first column.
Before manipulating the matrix, check if any 0 exist inside the first row/first col. If yes, then first row/first col will be manipulated lastly.
Next, for **OTHER** rows/cols, if matrix[i][j] = 0, check ith row as 0 with matrix[i][0] = 0; jth col as 0 with matrix[0][j] = 0.
Next, for **OTHER** row/cols, if matrix[i][0] == 0 || matrix[j][0] == 0, insert matrix[i][j] = 0.
Finally for the first row/col, manipulate them as 0 if the "original" 0 did exist inside themselves.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;
        for(int i=0; i<matrix.size(); i++) {
            if (matrix[i][0] == 0){
                firstCol = true;
                break;
            }
        }
        for(int j=0; j<matrix[0].size(); j++){
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[i].size(); j++){
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0; 
            }
        }
        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[i].size(); j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (firstCol){
            for(int i=0; i<matrix.size(); i++) matrix[i][0] = 0;
        }
        if (firstRow){
            for(int j=0; j<matrix[0].size(); j++) matrix[0][j] = 0;
        }
    }
};
