class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        int absx = abs(x);
        int ans = 0;
        while (absx > 0) {
            if (ans > 214748364) return 0;
            ans = ans * 10 + (absx % 10);
            absx /= 10;
        }
        return sign * ans;
    }
};
