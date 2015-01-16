class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans;
        for (int i = 0; i < n; ++i) ans.push_back(vector<int>(n, 0));
        int x = 0, y = -1;
        int cur = 1;
        while (cur <= n * n) {
            while (y + 1 < n && ans[x][y + 1] == 0) {
                y++;
                ans[x][y] = cur;
                cur++;
            }
            while (x + 1 < n && ans[x + 1][y] == 0) {
                x++;
                ans[x][y] = cur;
                cur++;
            }
            while (y - 1 >= 0 && ans[x][y - 1] == 0) {
                y--;
                ans[x][y] = cur;
                cur++;
            }
            while (x - 1 >= 0 && ans[x - 1][y] == 0) {
                x--;
                ans[x][y] = cur;
                cur++;
            }
        }
        return ans;
    }
};
