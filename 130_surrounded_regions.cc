class Solution {
public:
    void bfs(vector<vector<char> > &board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        queue<pair<int, int> > q;
        q.push(pair<int, int>(x, y));
        board[x][y] = 'L';
        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int new_x = front.first + dx[i];
                int new_y = front.second + dy[i];
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    if (board[new_x][new_y] == 'O') {
                        q.push(pair<int, int>(new_x, new_y));
                        board[new_x][new_y] = 'L';
                    }
                }
            }
        }
    }
    void solve(vector<vector<char> > &board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n - 1] == 'O') bfs(board, i, n - 1);
        }
        for (int i = 1; i < n - 1; ++i) {
            if (board[0][i] == 'O') bfs(board, 0, i);
            if (board[m - 1][i] == 'O') bfs(board, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'L') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
