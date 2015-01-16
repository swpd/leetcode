class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int len = n / 2;
        if (n % 2 != 0) {
            for (int i = 0; i < len; ++i) {
                int tmp = matrix[len][i];
                matrix[len][i] = matrix[n - 1 - i][len];
                matrix[n - 1 - i][len] = matrix[len][n - 1 - i];
                matrix[len][n - 1 - i] = matrix[i][len];
                matrix[i][len] = tmp;
            }
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};
