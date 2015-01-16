class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int stairs[3] = {1, 1, 0};
        for (int i = 1; i < n; ++i) {
            stairs[2] = stairs[0] + stairs[1];
            stairs[0] = stairs[1];
            stairs[1] = stairs[2];
        }
        return stairs[2];
    }
};
