class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return s;
        bool is_palind[1000][1000];
        memset(is_palind, 0, sizeof(is_palind));
        int start = 0, len = 1;
        for (int i = 0; i < n; ++i) is_palind[i][i] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (s[j] == s[j + i] && (i == 1 || is_palind[j + 1][j + i - 1])) {
                    if (i + 1 > len) {
                        len = i + 1;
                        start = j;
                    }
                    is_palind[j][j + i] = true;
                }
            }
        }
        return s.substr(start, len);
    }
};
