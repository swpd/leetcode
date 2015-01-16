class Solution {
public:
    bool isNumber(const char *s) {
        int len = strlen(s);
        if (len == 0) return true;
        int start = 0, end = len - 1;
        bool dot = false;
        while (start < end && (s[start] < '0' || s[start] > '9')) {
            if (s[start] == ' ') start++;
            else if (s[start] == '+' || s[start] == '-') {
                start++;
                break;
            } else if (s[start] == '.') {
                dot = true;
                start++;
                break;
            } else return false;
        }
        while (start < end && (s[end] < '0' || s[end] > '9')) {
            if (s[end] == ' ') end--;
            else if (s[end] == '.') break;
            else return false;
        }
        if (start == end) {
            if (s[start] >= '0' && s[start] <= '9') return true;
            else return false;
        }
        if (s[start] == '.') {
            if (!dot) {
                dot = true;
                start++;
            } else return false;
        }
        bool e = false;
        bool lead_num = false;
        for (int i = start; i <= end; ++i) {
            if (s[i] < '0' || s[i] > '9') {
                if (s[i] == 'e') {
                    if (!e && lead_num && i < end) e = true;
                    else return false;
                } else if (s[i] == '.') {
                    if (!dot && !e) dot = true;
                    else return false;
                } else if (s[i] == '+' || s[i] == '-') {
                    if (i > start && i < end && s[i - 1] == 'e') continue;
                    else return false;
                } else return false;
            } else {
                lead_num = true;
            }
        }
        return true;
    }
};
