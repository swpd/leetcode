class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<vector<int> > is_palind(n, vector<int> (n, false));
        for (int i = 0; i < n; ++i) is_palind[i][i] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (s[j] == s[j + i] && (i == 1 || is_palind[j + 1][j + i - 1])) is_palind[j][j + i] = true;
            }
        }
        vector<int> cut(n, -1);
        for (int i = 0; i < n; ++i) {
            if (is_palind[0][i]) cut[i] = 0;
            else {
                for (int j = 1; j <= i; ++j) {
                    if (is_palind[j][i]) {
                        int tmp = cut[j - 1] + 1;
                        if (cut[i] == -1 || cut[i] > tmp) cut[i] = tmp;
                    }
                }
            }
        }
        return cut[n - 1];
    }
};
