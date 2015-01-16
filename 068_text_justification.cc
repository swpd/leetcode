class Solution {
public:
    string build(vector<string> &words, int start, int end, int L) {
        int len = 0;
        for (int i = start; i < end; ++i) len += words[i].size();
        if (end == start + 1) return words[start] + string(L - len, ' ');
        string s;
        if (end == words.size()) {
            len += (end - start - 1);
            for (int i = start; i < end - 1; ++i) s = s + words[i] + " ";
            s += (words[end - 1] + string(L - len, ' '));
            return s;
        }
        int interval = (L - len) / (end - start - 1);
        int mid = (L - len) % (end - start - 1) + start;
        for (int i = start; i < mid; ++i) s = s + words[i] + string(interval + 1, ' ');
        for (int i = mid; i < end - 1; ++i) s = s + words[i] + string(interval, ' ');
        s += words[end - 1];
        return s;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        int n = words.size();
        vector<string> ans;
        int start = 0, end = 0;
        int len = 0;
        while (end < n) {
            if (len == 0) {
                len = words[end].size();
                end++;
            } else {
                if (len + 1 + words[end].size() <= L) {
                    len += (1 + words[end].size());
                    end++;
                } else {
                    ans.push_back(build(words, start, end, L));
                    start = end;
                    len = 0;
                }
            }
        }
        ans.push_back(build(words, start, end, L));
        return ans;
    }
};
