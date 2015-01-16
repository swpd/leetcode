class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string ans;
        int n = s.size();
        for (int i = 0; i < n; i += 2 * (nRows - 1)) ans += s[i];
        for (int i = 1; i < nRows - 1; ++i) {
            int offset = 2 * (nRows - i - 1);
            int j = i;
            while (j < n) {
                ans += s[j];
                j += offset;
                offset = 2 * (nRows - 1) - offset;
            }
        }
        for (int i = nRows - 1; i < n; i += 2 * (nRows - 1)) ans += s[i];
        return ans;
    }
};
