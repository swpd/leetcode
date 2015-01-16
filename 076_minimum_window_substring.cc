class Solution {
public:
    string minWindow(string S, string T) {
        int sn = S.size();
        int tn = T.size();
        string ans;
        if (sn < tn) return ans;
        unordered_map<char, int> m;
        for (int i = 0; i < tn; ++i) m[T[i]]++;
        int total = 0;
        int min_len = -1;
        int front = -1;
        for (int i = 0; i < sn; ++i) {
            if (m.find(S[i]) != m.end()) {
                if (front == -1) front = i;
                m[S[i]]--;
                if (m[S[i]] >= 0) {
                    // still have slots
                    total++;
                } else {
                    if (S[front] == S[i]) {
                        while (true) {
                            if (m.find(S[front]) != m.end()) {
                                if (m[S[front]] < 0) m[S[front]]++;
                                else break;
                            }
                            front++;
                        }
                    }
                }
                if (total == tn) {
                    if (min_len == -1 || min_len > i - front + 1) {
                        min_len = i - front + 1;
                        ans = S.substr(front, min_len);
                    }
                }
            }
        }
        return ans;
    }
};
