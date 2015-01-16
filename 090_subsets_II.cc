class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans(1);
        sort(S.begin(), S.end());
        int n = S.size();
        int cnt, pre;
        for (int i = 0; i < n; ++i) {
            int ans_n = ans.size();
            if (i == 0 || S[i] != S[i - 1]) {
                cnt = ans_n;
                pre = cnt;
            } else cnt = pre;
            for (int j = ans_n - cnt; j < ans_n; ++j) {
                vector<int> v(ans[j]);
                v.push_back(S[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
