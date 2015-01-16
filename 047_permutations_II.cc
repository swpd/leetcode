class Solution {
public:
    bool next(vector<int> &num) {
        int n = num.size();
        int less_idx = n - 2;
        while (less_idx >= 0) {
            if (num[less_idx + 1] > num[less_idx]) break;
            else less_idx--;
        }
        if (less_idx == -1) {
            reverse(num.begin(), num.end());
            return false;
        }
        for (int i = n - 1; i > less_idx; --i) {
            if (num[i] > num[less_idx]) {
                swap(num[i], num[less_idx]);
                break;
            }
        }
        reverse(num.begin() + less_idx + 1, num.end());
        return true;
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        ans.push_back(num);
        while (next(num)) ans.push_back(num);
        return ans;
    }
};
