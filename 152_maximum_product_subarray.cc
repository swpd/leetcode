class Solution {
public:
    int maxProduct(int A[], int n) {
        int pos, neg;
        int last_pos, last_neg;
        int ans = A[0];
        pos = (A[0] > 0) ? A[0] : 0;
        neg = (A[0] < 0) ? A[0] : 0;
        for (int i = 1; i < n; ++i) {
            last_pos = pos;
            last_neg = neg;
            if (A[i] > 0) {
                if (last_pos > 0)
                    pos = last_pos * A[i];
                else
                    pos = A[i];
                neg = last_neg * A[i];
            } else if (A[i] < 0) {
                if (last_pos > 0)
                    neg = last_pos * A[i];
                else
                    neg = A[i];
                pos = last_neg * A[i];
            } else {
                pos = 0;
                neg = 0;
            }
            if (pos > ans) ans = pos;
        }
        return ans;
    }
};
