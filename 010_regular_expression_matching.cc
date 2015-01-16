class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p) return false;
        int lens = strlen(s);
        int lenp = strlen(p);
        bool match[lens + 1][lenp + 1];
        memset(match, 0, sizeof(match));
        match[0][0] = true;
        for (int i = 1; i <= lenp; ++i) {
            if (p[i - 1] == '*') match[0][i] = match[0][i - 2];
            else match[0][i] = false;
        }
        for (int i = 1; i <= lens; ++i) {
            for (int j = 1; j <= lenp; ++j) {
                if (p[j - 1] == '*') {
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) match[i][j] = match[i - 1][j] || match[i][j - 2];
                    else match[i][j] = match[i][j - 2];
                } else if (p[j - 1] == '.') {
                    match[i][j] = match[i - 1][j - 1];
                } else {
                    if (p[j - 1] == s[i - 1]) match[i][j] = match[i - 1][j - 1];
                    else match[i][j] = false;
                }
            }
        }
        return match[lens][lenp];
    }
};
