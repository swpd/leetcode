class Solution {
public:
    bool is_valid(string &s, int start, int len) {
        if (len > 1 && s[start] == '0') return false;
        int n = 0;
        for (int i = 0; i < len; ++i) n = n * 10 + (s[start + i] - '0');
        if (n > 255) return false;
        return true;
    }
    vector<string> restoreIpAddresses(string &s, int parts, int start) {
        vector<string> ans;
        int n = s.size() - start;
        if (n < parts || n > 3 * parts) return ans;
        for (int i = 1; i <= 3 && i <= n; ++i) {
            if (is_valid(s, start, i)) {
                string tmp = s.substr(start, i);
                if (parts == 1) {
                    if (i == n) ans.push_back(tmp);
                } else {
                    vector<string> sub_ans = restoreIpAddresses(s, parts - 1, start + i);
                    int len = sub_ans.size();
                    for (int j = 0; j < len; ++j) ans.push_back(tmp + "." + sub_ans[j]);
                }
            }
        }
        return ans;
    }
    vector<string> restoreIpAddresses(string s) {
        return restoreIpAddresses(s, 4, 0);
    }
};
