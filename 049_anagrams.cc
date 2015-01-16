class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, int> m;
        vector<string> ans;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (m.find(tmp) == m.end()) m[tmp] = 1;
            else m[tmp] += 1;
        }
        for (int i = 0; i < n; ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (m[tmp] > 1) ans.push_back(strs[i]);
        }
        return ans;
    }
};
