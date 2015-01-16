class Solution {
public:
    bool dfs(vector<vector<char> > &board, string &word, int start, vector<vector<bool> > &visited, int x, int y) {
        if (word.size() == start) return true;
        int m = board.size();
        int n = board[0].size();
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[start]) return false;
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (dfs(board, word, start + 1, visited, new_x, new_y)) return true;
        }
        visited[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, visited, i, j)) return true;
            }
        }
        return false;
    }
};
