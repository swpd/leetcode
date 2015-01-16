class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> visited(9, false);
        for (int i = 0; i < 9; ++i) {
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int idx = board[i][j] - '1';
                    if (visited[idx]) return false;
                    else visited[idx] = true;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            fill(visited.begin(), visited.end(), false);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] >= '1' && board[j][i] <= '9') {
                    int idx = board[j][i] - '1';
                    if (visited[idx]) return false;
                    else visited[idx] = true;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                fill(visited.begin(), visited.end(), false);
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        int x = i * 3 + k, y = j * 3 + l;
                        if (board[x][y] >= '1' && board[x][y] <= '9') {
                            int idx = board[x][y] - '1';
                            if (visited[idx]) return false;
                            else visited[idx] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
