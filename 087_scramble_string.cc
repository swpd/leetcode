class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        if (n <= 3) return true;
        for (int i = 1; i < n; ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, i), r2 = s2.substr(i);
            if (isScramble(l1, l2) && isScramble(r1, r2)) return true;
            l2 = s2.substr(0, n - i), r2 = s2.substr(n - i);
            if (isScramble(l1, r2) && isScramble(r1, l2)) return true;
        }
        return false;
    }
};
