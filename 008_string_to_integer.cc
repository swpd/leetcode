class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str);
        int i = 0;
        bool neg = false;
        while (str[i] < '0' || str[i] > '9') {
            if (str[i] == ' ') i++;
            else if (str[i] == '-') {
                neg = true;
                i++;
                break;
            } else if (str[i] == '+') {
                i++;
                break;
            } else return 0;
        }
        int ans = 0;
        for (; i < len; ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                if (ans > 214748364) {
                    if (neg) return INT_MIN;
                    else return INT_MAX;
                }
                if (ans == 214748364) {
                    if (neg && str[i] > '8') return INT_MIN;
                    else if (!neg && str[i] > '7') return INT_MAX;
                }
                ans = ans * 10 + (str[i] - '0');
            } else break;
        }
        if (neg) ans = -ans;
        return ans;
    }
};
