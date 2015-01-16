class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target, int n) {
        vector<vector<int> > ans;
        for (int i = n - 1; i >= 0; --i) {
            if (target == candidates[i]) {
                vector<int> v;
                v.push_back(target);
                ans.push_back(v);
            } else if (target > candidates[i]) {
                vector<vector<int> > sub_ans = combinationSum(candidates, target - candidates[i], i + 1);
                int len = sub_ans.size();
                for (int j = 0; j < len; ++j) {
                    sub_ans[j].push_back(candidates[i]);
                    ans.push_back(sub_ans[j]);
                }
            }
        }
        return ans;
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        return combinationSum(candidates, target, n);
    }
};
