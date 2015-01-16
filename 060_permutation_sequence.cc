class Solution {
public:
    string getPermutation(int n, int k) {
        const int fact[] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<int> elem;
        for (int i = 0; i < n; ++i) elem.push_back(i);
        k--;
        string s;
        for (int i = n - 2; i >= 0; --i) {
            int d = k / fact[i];
            for (int j = 0; j < n; ++j) {
                if (elem[j] == d) {
                    s.push_back(j + 1 + '0');
                    elem[j] = -1;
                    for (int k = j + 1; k < n; ++k) elem[k]--;
                    break;
                }
            }
            k -= d * fact[i];
        }
        for (int i = 0; i < n; ++i) {
            if (elem[i] == k) s.push_back(i + 1 + '0');
        }
        return s;
    }
};
