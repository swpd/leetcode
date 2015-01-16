class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> um;
        int n = s.size();
        int len = 0;
        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (um.find(s[i]) != um.end() && start < um[s[i]]) start = um[s[i]];
            um[s[i]] = i;
            len = max(len, i - start);
        }
        return len;
    }
};
