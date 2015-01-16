class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n, 0);
        for (int i = 0; i < n; ++i) {
            int half = 1 << i;
            for (int j = 0; j < half; ++j) ans[2 * half - 1 - j] = ans[j] + half;
        }
        return ans;
    }
};
