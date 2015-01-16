class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        int n = path.size();
        int start = 0, end = 0;
        int i = 1;
        stack<string> stk;
        while (i < n) {
            if (path[i] == '/') {
                end = i;
                if (end == start + 2 && path[start + 1] != '.') stk.push(path.substr(start + 1, 1));
                if (end == start + 3) {
                    string sub_str = path.substr(start + 1, 2);
                    if (sub_str == "..") {
                        if (!stk.empty()) stk.pop();
                    } else stk.push(sub_str);
                }
                if (end > start + 3) stk.push(path.substr(start + 1, end - start - 1));
                start = end;
            }
            i++;
        }
        string ans;
        while (!stk.empty()) {
            string parent = "/" + stk.top();
            ans = parent + ans;
            stk.pop();
        }
        if (ans.empty()) return "/";
        return ans;
    }
};
