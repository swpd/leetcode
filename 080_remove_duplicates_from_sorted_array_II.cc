class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        bool is_allowed = true;
        int curr = 0;
        for (int i = 1; i < n; ++i) {
            if (A[curr] == A[i]) {
                if (is_allowed) {
                    A[curr + 1] = A[i];
                    curr++;
                    is_allowed = false;
                }
            } else {
                A[curr + 1] = A[i];
                curr++;
                is_allowed = true;
            }
        }
        return curr + 1;
    }
};
