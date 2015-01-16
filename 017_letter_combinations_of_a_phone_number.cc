class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, string > m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        int d_len = digits.size();
        if (d_len == 0) {
            ans.push_back("");
            return ans;
        }
        string head = m[digits[0]];
        int h_len = head.size();
        vector<string> sub_ans = letterCombinations(digits.substr(1));
        int sub_len = sub_ans.size();
        for (int i = 0; i < h_len; ++i) {
            for (int j = 0; j < sub_len; ++j) {
                string s;
                s += head[i];
                s += sub_ans[j];
                ans.push_back(s);
            }
        }
        return ans;
    }
};
