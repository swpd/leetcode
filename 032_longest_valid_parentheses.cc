class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len == 0) return 0;
        stack<int> stk;
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.empty()) {
                    start = i + 1;
                } else {
                    stk.pop();
                    if (stk.empty()) {
                        int cur = i - start + 1;
                        if (cur > max_len) max_len = cur;
                    } else {
                        int cur = i - stk.top();
                        if (cur > max_len) max_len = cur;
                    }
                }
            }
        }
        return max_len;
    }
};
