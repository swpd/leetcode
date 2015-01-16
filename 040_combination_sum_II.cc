class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target, int n) {
        vector<vector<int> > ans;
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && num[i] == num[i + 1]) continue;
            if (target == num[i]) {
                vector<int> v;
                v.push_back(num[i]);
                ans.push_back(v);
            } else if (target > num[i]) {
                vector<vector<int> > sub_ans = combinationSum2(num, target - num[i], i);
                int len = sub_ans.size();
                for (int j = 0; j < len; ++j) {
                    sub_ans[j].push_back(num[i]);
                    ans.push_back(sub_ans[j]);
                }
            }
        }
        return ans;
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        return combinationSum2(num, target, num.size());
    }
};
