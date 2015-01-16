class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        vector<int> tmp(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) tmp[j] = ans[j - 1] + ans[j];
            for (int j = 1; j < i; ++j) ans[j] = tmp[j];
        }
        return ans;
    }
};
