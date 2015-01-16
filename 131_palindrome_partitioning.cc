class Solution {
public:
    vector<vector<string> > helper(vector<vector<bool> > &is_palind, string s, int end) {
        vector<vector<string> > ans;
        int n = s.size();
        if (end == 0) {
            ans.push_back(vector<string>());
            return ans;
        }
        for (int i = end - 1; i >= 0; --i) {
            if (is_palind[i][end - 1]) {
                vector<vector<string> > sub_ans = helper(is_palind, s, i);
                int sub_len = sub_ans.size();
                for (int j = 0; j < sub_len; ++j) {
                    sub_ans[j].push_back(s.substr(i, end - i));
                    ans.push_back(sub_ans[j]);
                }
            }
        }
        return ans;
    }
    vector<vector<string> > partition(string s) {
        int n = s.size();
        vector<vector<bool> > is_palind(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) is_palind[i][i] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (s[j] == s[j + i]) {
                    if (i == 1 || is_palind[j + 1][j + i - 1]) is_palind[j][j + i] = true;
                }
            }
        }
        return helper(is_palind, s, n);
    }
};
