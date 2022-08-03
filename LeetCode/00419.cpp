class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                // increase cnt only if i,j is the left upper corner of the battleship.
                if (board[i][j] == 'X') {
                    if ((i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.')) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
// Or, we can do BFS by muting board's 'X' to '.'
// This cannot be done when the memory is not large enough to contain the whole
// board.
