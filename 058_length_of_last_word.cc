class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (!s) return 0;
        int len = strlen(s);
        int ans = 0;
        bool enter_word = false;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
                if (!enter_word) {
                    enter_word = true;
                }
                ans++;
            } else {
                if (enter_word) break;
            }
        }
        return ans;
    }
};
