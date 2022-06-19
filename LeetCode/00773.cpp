class Solution {
public:
    vector<int> game_plate;
    const int magic_plate = (1 << 0) + 2 * (1 << 3) + 3 * (1 << 6) + 4 * (1 << 9) + 5 * (1 << 12);
    int return_cellval(int cell_idx, int game_plate_num) {
        return ((game_plate_num) >> (3 * cell_idx)) % 8;
    }
    vector<vector<int>> next_zero_mvmts;
    vector<int> zero_mvmts(int zero_idx) {
        switch(zero_idx) {
            case 0:
                return vector<int>{1, 3};
            case 1:
                return vector<int>{0, 2, 4};
            case 2:
                return vector<int>{1, 5};
            case 3:
                return vector<int>{0, 4};
            case 4:
                return vector<int>{1, 3, 5};
            case 5:
                return vector<int>{2, 4};
        }
        return vector<int>();
    }
    
    int bfs(int game_plate_num, int zero_idx) {
        using pii = pair<int, int>;
        using piii = pair<pii, int>;
        // queue<piii> game_idx;
        queue<pii> game_idx;
        //game_idx.push_back({{game_plate_num, zero_idx}, 0});
        game_idx.push({game_plate_num, zero_idx});
        while(!game_idx.empty()) {
            pii curr_idx = game_idx.front();
            game_idx.pop();
            int curr_game_plate_num = curr_idx.first;
            if (curr_game_plate_num == magic_plate) {
                return game_plate[curr_game_plate_num];
            }
            int curr_zero_idx = curr_idx.second;
            for(int next_zero_idx: next_zero_mvmts[curr_zero_idx]) {
                int exchangable_cellval = return_cellval(next_zero_idx, curr_game_plate_num);
                int next_game_plate_num = curr_game_plate_num;
                next_game_plate_num -= exchangable_cellval * (1 << (3 * next_zero_idx));
                next_game_plate_num += exchangable_cellval * (1 << (3 * curr_zero_idx));
                if (game_plate[next_game_plate_num] != -1) continue;
                game_plate[next_game_plate_num] = game_plate[curr_game_plate_num] + 1;
                game_idx.push({next_game_plate_num, next_zero_idx});
            }
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        game_plate = vector<int>(1 << 18, -1);
        // Sol) Use bit_dp. For each cell, describe its value by 3-bits.
        // Then this plate becomes 18bit array.
        // Our goal is finding whether or not [001010011100101000(little_endian)] is reachable.
        int init_game_plate_num = 0;
        int init_zero_idx = -1;
        for(int i=0; i<6; i++) {
            int board_val = board[i/3][i%3];
            init_game_plate_num += board_val * (1 << (3 * i));
            if (board_val == 0) init_zero_idx = i;
        }
        if (magic_plate == init_game_plate_num) return 0;
        next_zero_mvmts = vector<vector<int>>(6, vector<int>());
        for(int i=0; i<6; i++) {
            next_zero_mvmts[i] = zero_mvmts(i);
        }
        game_plate[init_game_plate_num] = 0;
        int trials = bfs(init_game_plate_num, init_zero_idx);
        return trials;
    }
};

/* NOTE: This method takes too much memory (as I use 2^18 space.)
 * It can actually be solved with permutations.
 * Since we have 0 ~ 5, game plate can be expressed with 720 different
 * permutations.
 * We even don't have to predefine connections with adjacent matrix. Since
 * exchange operation between 0 and others are restricted, that exchangable
 * operation automatically means edge.
 * By doing bfs on that 720 node graph, we can find the shortest path.
 * Actually, my method also uses only 720 different indices, but 2^18 is too
 * sparse to contain them.
 * If I have more time, let's fix in that way.
 */
