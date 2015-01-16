class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        if (m == 0 || m < n) return 0;
        vector<int> ans(m, 1);
        for (int i = 0; i < n; ++i) {
            int tmp;
            if (i == 0) tmp = 1;
            else tmp = ans[i - 1];
            for (int j = i; j < m; ++j) {
                int new_ans;
                if (j == i) new_ans = 0;
                else new_ans = ans[j - 1];
                if (S[j] == T[i]) new_ans += tmp;
                tmp = ans[j];
                ans[j] = new_ans;
            }
            if (ans[m - 1] == 0) return 0;
        }
        return ans[m - 1];
    }
};
