class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        unordered_map<string, int> m;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            int len = strs[i].size();
            for (int j = 1; j <= len; ++j) m[strs[i].substr(0, j)] += 1;
        }
        string longest_prefix;
        unordered_map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it) {
            if (it->second == n && (it->first).size() > longest_prefix.size()) longest_prefix = it->first;
        }
        return longest_prefix;
    }
};
