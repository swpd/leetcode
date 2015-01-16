class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            int val = matrix[row][col];
            if (val == target) return true;
            if (val < target) row++;
            if (val > target) col--;
        }
        return false;
    }
};
