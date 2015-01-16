class Solution {
public:
    bool valid(int row, int col, vector<int> &location) {
        for (int i = 0; i < row; ++i) {
            if ((abs(i - row) == abs(location[i] - col)) || (location[i] == col)) return false;
        }
        return true;
    }
    void dfs(int n, int row, vector<int> &location, int &ans) {
        for (int i = 0; i < n; ++i) {
            if (valid(row, i, location)) {
                location[row] = i;
                if (row == n - 1) {
                    ans++;
                } else {
                    dfs(n, row + 1, location, ans);
                }
                location[row] = -1;
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> location(n, -1);
        dfs(n, 0, location, ans);
        return ans;
    }
};
