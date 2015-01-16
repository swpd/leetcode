class Solution {
public:
    int singleNumber(int A[], int n) {
        int cnt[32] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                cnt[j] += (A[i] >> j) & 1;
            }
        }
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            ans = ans * 2 + (cnt[i] % 3);
        }
        return ans;
    }
};
