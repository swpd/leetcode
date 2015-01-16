class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        int m = word1.size(), n = word2.size();
        int dis[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) dis[i][0] = i;
        for (int i = 1; i <= n; ++i) dis[0][i] = i;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) dis[i][j] = dis[i - 1][j - 1];
                else dis[i][j] = min(min(dis[i - 1][j], dis[i][j - 1]), dis[i - 1][j - 1]) + 1;
            }
        }
        return dis[m][n];
    }
};
