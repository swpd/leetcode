class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
                else triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        int min_sum = triangle[n - 1][0];
        for (int i = 1; i < n; ++i) {
            if (triangle[n - 1][i] < min_sum) min_sum = triangle[n - 1][i];
        }
        return min_sum;
    }
};
