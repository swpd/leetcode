class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int row = m + n - 2;
        int col = m - 1;
        int j = 1;
        for (int i = n; i <= row; ++i) {
            ans *= i;
            while (ans % j == 0 && j <= col) {
                ans /= j;
                j++;
            }
        }
        return ans;
    }
};
