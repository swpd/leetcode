class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool> > visited;
        for (int i = 0; i < m; ++i) visited.push_back(vector<bool>(n, false));
        int total = 1;
        int x = 0, y = -1;
        while (total <= m * n) {
            while (y + 1 < n && !visited[x][y + 1]) {
                y++;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                total++;
            }
            while (x + 1 < m && !visited[x + 1][y]) {
                x++;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                total++;
            }
            while (y - 1 >= 0 && !visited[x][y - 1]) {
                y--;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                total++;
            }
            while (x - 1 >= 0 && !visited[x - 1][y]) {
                x--;
                visited[x][y] = true;
                ans.push_back(matrix[x][y]);
                total++;
            }
        }
        return ans;
    }
};
