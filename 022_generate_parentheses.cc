class Solution {
public:
    void helper(int n, string s, int left, int right, vector<string> &ans) {
        if (left == n && right == n) ans.push_back(s);
        else {
            if (left < n) helper(n, s + "(", left + 1, right, ans);
            if (right < left) helper(n, s + ")", left, right + 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(n, s, 0, 0, ans);
        return ans;
    }
};
