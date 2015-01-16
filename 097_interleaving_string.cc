class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int len = s3.size();
        if (m + n != len) return false;
        bool can[m + 1][n + 1];
        memset(can, 0, sizeof(can));
        can[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (s1[i - 1] == s3[i - 1]) can[i][0] = true;
            else break;
        }
        for (int i = 1; i <= n; ++i) {
            if (s2[i - 1] == s3[i - 1]) can[0][i] = true;
            else break;
        }
        for (int i = 2; i <= len; ++i) {
            for (int j = 1; j < i && j <= m; ++j) {
                if (s3[i - 1] == s1[j - 1] && can[j - 1][i - j]) can[j][i - j] = true;
                if (s3[i - 1] == s2[i - j - 1] && can[j][i - j - 1]) can[j][i - j] = true;
            }
        }
        return can[m][n];
    }
};
