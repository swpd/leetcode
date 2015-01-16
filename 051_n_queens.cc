class Solution {
public:
    bool valid(int n, int row, int col, vector<int> &location, vector<string> &sol) {
        for (int i = 0; i < row; ++i) {
            if ((abs(i - row) == abs(location[i] - col)) || (location[i] == col)) return false;
        }
        return true;
    }
    void dfs(int n, int row, vector<int> &location, vector<string> &sol, vector<vector<string> > &ans) {
        for (int i = 0; i < n; ++i) {
            if (valid(n, row, i, location, sol)) {
                sol[row][i] = 'Q';
                location[row] = i;
                if (row == n - 1) {
                    ans.push_back(sol);
                } else {
                    dfs(n, row + 1, location, sol, ans);
                }
                sol[row][i] = '.';
                location[row] = -1;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> sol(n, string(n, '.'));
        vector<int> location(n, -1);
        dfs(n, 0, location, sol, ans);
        return ans;
    }
};
