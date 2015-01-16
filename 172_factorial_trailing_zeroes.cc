class Solution {
public:
    int trailingZeroes(int n) {
        long long ans = 0;
        long long base = 5;
        while (n >= base) {
            ans += n / base;
            base *= 5;
        }
        return ans;
    }
};
