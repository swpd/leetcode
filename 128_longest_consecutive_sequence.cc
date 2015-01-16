class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int n = num.size();
        int ans = 1;
        if (n == 0) return 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.find(num[i]) == m.end()) {
                m[num[i]] = 1;
                int l = num[i], r = num[i];
                int l_max = 0, r_max = 0;
                if (m.find(num[i] - 1) != m.end()) {
                    l = num[i] - m[num[i] - 1];
                    l_max = m[l];
                }
                if (m.find(num[i] + 1) != m.end()) {
                    r = num[i] + m[num[i] + 1];
                    r_max = m[r];
                }
                m[l] = m[r] = 1 + l_max + r_max;
                ans = max(ans, m[l]);
            }
        }
        return ans;
    }
};
