class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || m[s[i]] <= m[s[i - 1]]) ans += m[s[i]];
            else ans += (m[s[i]] - 2 * m[s[i - 1]]);
        }
        return ans;
    }
};
