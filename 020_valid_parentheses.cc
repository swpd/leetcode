class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (stk.empty()) stk.push(s[i]);
            else {
                char top = stk.top();
                if (top == '(' && s[i] == ')' || top == '[' && s[i] == ']' || top == '{' && s[i] == '}')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};
