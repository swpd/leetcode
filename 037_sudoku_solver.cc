class Solution {
public:
    void set_use(int i, int j, int val, bool used) {
        row_is_used[i][val] = used;
        col_is_used[j][val] = used;
        sub_is_used[i / 3 * 3 + j / 3][val] = used;
    }
    
    bool helper(vector<vector<char> > &board, int index) {
        if (index == 81) return true;
        int x = index / 9, y = index % 9;
        if (board[x][y] != '.') return helper(board, index + 1);
        for (int i = 1; i <= 9; ++i) {
            char c = i + '0';
            if (!(row_is_used[x][i - 1] || col_is_used[y][i - 1] || sub_is_used[x / 3 * 3 + y / 3][i - 1])) {
                board[x][y] = c;
                set_use(x, y, i - 1, true);
                if (helper(board, index + 1)) return true;
                set_use(x, y, i - 1, false);
                board[x][y] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') set_use(i, j, board[i][j] - '0' - 1, true);
            }
        }
        helper(board, 0);
    }
private:
    bool row_is_used[9][9];
    bool col_is_used[9][9];
    bool sub_is_used[9][9];
};
