class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int Ln = L.size();
        vector<int> ans;
        if (Ln == 0) return ans;
        map<string, int> count, cur_count;
        for (int i = 0; i < Ln; ++i) count[L[i]]++;
        int len = L[0].size();
        int Sn = S.size();
        for (int i = 0; i <= Sn - len * Ln; ++i) {
            cur_count.clear();
            bool match = true;
            for (int j = 0; j < Ln; ++j) {
                string w = S.substr(i + j * len, len);
                if (count.find(w) == count.end()) {
                    match = false;
                    break;
                } else{
                    cur_count[w]++;
                    if (cur_count[w] > count[w]) {
                        match = false;
                        break;
                    }
                }
            }
            if (match) ans.push_back(i);
        }
        return ans;
    }
};
