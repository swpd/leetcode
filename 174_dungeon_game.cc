class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<int> min_blood(n);
        min_blood[n - 1] = dungeon[m - 1][n - 1] > 0 ? 1 : 1 - dungeon[m - 1][n - 1];
        for (int i = n - 2; i >= 0; --i) min_blood[i] = max(min_blood[i + 1] - dungeon[m - 1][i], 1);
        for (int i = m - 2; i >= 0; --i) {
            min_blood[n - 1] = max(min_blood[n - 1] - dungeon[i][n - 1], 1);
            for (int j = n - 2; j >= 0; --j) min_blood[j] = max(min(min_blood[j + 1], min_blood[j]) - dungeon[i][j], 1);
        }
        return min_blood[0];
    }
};
