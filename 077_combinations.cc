class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        if (n < k) return ans;
        if (k == 0) {
            vector<int> v;
            ans.push_back(v);
            return ans;
        }
        for (int i = n; i >= k - 1; --i) {
            vector<vector<int> > sub_ans = combine(i - 1, k - 1);
            int len = sub_ans.size();
            for (int j = 0; j < len; ++j) {
                sub_ans[j].push_back(i);
                ans.push_back(sub_ans[j]);
            }
        }
        return ans;
    }
};
