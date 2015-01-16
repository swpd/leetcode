class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0) return 1;
        for (int i = 0; i < n; ++i) {
            int cur = A[i];
            while (cur > 0 && cur <= n && cur != A[cur - 1]) {
                swap(cur, A[cur - 1]);
            }
            if (A[i] != i + 1) A[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] == -1) return i + 1;
        }
        return n + 1;
    }
};
