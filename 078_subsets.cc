class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        int n = S.size();
        int total = 1 << n;
        int mask[n];
        for (int i = 0; i < n; ++i) mask[i] = 1 << i;
        sort(S.begin(), S.end());
        for (int i = 0; i < total; ++i) {
            vector<int> v;
            for (int j = 0; j < n; ++j) {
                if (mask[j] & i) v.push_back(S[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
