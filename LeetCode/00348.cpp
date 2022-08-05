class TicTacToe {
public:
    vector<vector<int>> row_count;
    vector<vector<int>> col_count;
    vector<vector<int>> diag_count;
    int size;
    TicTacToe(int n) {
        size = n;
        row_count = vector<vector<int>>(2, vector<int>(n));
        col_count = vector<vector<int>>(2, vector<int>(n));
        diag_count = vector<vector<int>>(2, vector<int>(2));
    }
    
    int move(int row, int col, int player) {
        row_count[player - 1][row] += 1;
        col_count[player - 1][col] += 1;
        if (row == col) diag_count[player - 1][0] += 1;
        if (row + col == size - 1) diag_count[player - 1][1] += 1;
        if (row_count[player - 1][row] == size || col_count[player - 1][col] == size || diag_count[player - 1][0] == size || diag_count[player - 1][1] == size)
            return player;
        return 0;
    }
};
