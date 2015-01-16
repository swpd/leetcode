class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!s || !p) return false;
        int lens = strlen(s);
        int lenp = strlen(p);
        int count = 0;
        for (int i = 0; i < lenp; ++i) {
            if (p[i] != '*') count++;
        }
        if (count > lens) return false;
        bool match[lenp + 1];
        memset(match, 0, sizeof(match));
        match[0] = true;
        for (int i = 1; i <= lenp; ++i) {
            if (p[i - 1] == '*') match[i] = true;
            else break;
        }
        for (int i = 1; i <= lens; ++i) {
            bool left_up = match[0];
            match[0] = false; // (input, "")
            for (int j = 1; j <= lenp; ++j) {
                if (p[j - 1] == '*') {
                    // store before update
                    left_up = match[j];
                    match[j] = match[j] || match[j - 1];
                } else if (p[j - 1] == '?') {
                    swap(left_up, match[j]);
                } else {
                    if (p[j - 1] == s[i - 1]) {
                        swap(left_up, match[j]);
                    } else {
                        left_up = match[j];
                        match[j] = false;
                    }
                }
            }
        }
        return match[lenp];
    }
};
