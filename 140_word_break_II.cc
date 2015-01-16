class Solution {
public:
    vector<string> helper(vector<vector<int> > &dp, int idx, string &s) {
        vector<string> ans;
        int n = dp[idx].size();
        for (int i = 0; i < n; ++i) {
            if (dp[idx][i] > 0) {
                vector<string> sub_ans = helper(dp, dp[idx][i], s);
                int sub_len = sub_ans.size();
                string tail = s.substr(dp[idx][i], idx - dp[idx][i]);
                for (int j = 0; j < sub_len; ++j) ans.push_back(sub_ans[j] + " " + tail);
            } else ans.push_back(s.substr(0, idx));
        }
        return ans;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<vector<int> > dp(n + 1, vector<int>());
        dp[0].push_back(0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dict.find(s.substr(j, i - j)) != dict.end() && !dp[j].empty()) dp[i].push_back(j);
            }
        }
        return helper(dp, n, s);
    }
};
