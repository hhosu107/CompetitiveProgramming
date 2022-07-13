class Solution {
public:
    pair<int, int> decode_cellnum(int num, int n) {
        // 1 -> [n-1, 0] / n -> [n-1, n-1] / ... [n^2] -> [0, n-1].
        int row = (n - 1) - (num - 1) / n;
        int col = (num - 1) % n;
        if (((num - 1) / n) % 2 == 1) {
            col = n - 1 - (num - 1) % n;
        }
        return make_pair(row, col);
    }
    int encode_cellnum(int x, int y, int n) {
        int rev_row = (n - 1) - x;
        int col = y;
        if (rev_row % 2 == 1) {
            col = n - 1 - y;
        }
        return rev_row * n + y + 1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 2) return 1;
        vector<vector<int>> visited(n, vector<int>(n, n * n + 1));
        queue<int> cell;
        visited[n-1][0] = 0;
        cell.push(1);
        while(!cell.empty()) {
            int curr = cell.front();
            cell.pop();
            for(int i=1; i<=6; i++) {
                int new_cell = i + curr;
                pair<int, int> decoded_curr = decode_cellnum(curr, n);
                if (i + curr >= n * n) {
                    return visited[decoded_curr.first][decoded_curr.second] + 1;
                }
                pair<int, int> decoded_new_cell = decode_cellnum(new_cell, n);
                if (board[decoded_new_cell.first][decoded_new_cell.second] == n * n) return visited[decoded_curr.first][decoded_curr.second] + 1;
                if (visited[decoded_new_cell.first][decoded_new_cell.second] < n * n + 1 && board[decoded_new_cell.first][decoded_new_cell.second] == -1) continue;
                pair<int, int> jumped_next = decode_cellnum(board[decoded_new_cell.first][decoded_new_cell.second], n);
                if (board[decoded_new_cell.first][decoded_new_cell.second] != -1) {
                    if (visited[jumped_next.first][jumped_next.second] < n * n + 1) continue;
                }
                int next_cell = (board[decoded_new_cell.first][decoded_new_cell.second] != -1 ? board[decoded_new_cell.first][decoded_new_cell.second] : new_cell);
                pair<int, int> next_decoded_cell = (board[decoded_new_cell.first][decoded_new_cell.second] != -1 ? jumped_next : decoded_new_cell);
                visited[next_decoded_cell.first][next_decoded_cell.second] = visited[decoded_curr.first][decoded_curr.second] + 1;
                cell.push(next_cell);
            }
        }
        return -1;
    }
};

// TODO: just establish visited[] as 1 dimensional vector. Use decode only when
// needed. Reuse board[][]s.
