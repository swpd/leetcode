class Solution {
public:
    void build_next(char *str, vector<int> &next) {
        int n = strlen(str);
        next.push_back(-1);
        int i = 0, j = -1;
        while (i < n) {
            if (j == -1 || str[i] == str[j]) {
                i++;
                j++;
                next.push_back(j);
            } else j = next[j];
        }
    }
    char *strStr(char *haystack, char *needle) {
        if (!needle || !strcmp(needle, "")) return haystack;
        int len_h = strlen(haystack);
        int len_n = strlen(needle);
        vector<int> next;
        build_next(needle, next);
        int i = 0, j = 0;
        while (i < len_h && j < len_n) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else j = next[j];
        }
        if (j == len_n) return haystack + i - j;
        else return NULL;
    }
};
