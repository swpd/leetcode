class Solution {
public:
    int strToInt(string &s) {
        int ans = 0;
        bool neg = (s[0] == '-');
        int i = 0;
        if (neg) i = 1;
        for (; i < s.length(); ++i) {
            ans = ans * 10 + (s[i] - '0');
        }
        if (neg) return -ans;
        else return ans;
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if (tokens[i] == "+") s.push(a + b);
                if (tokens[i] == "-") s.push(b - a);
                if (tokens[i] == "*") s.push(a * b);
                if (tokens[i] == "/") s.push(b / a);
            } else {
                s.push(strToInt(tokens[i]));
            }
        }
        return s.top();
    }
};
