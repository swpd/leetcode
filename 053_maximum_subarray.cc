class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, max_sum = A[0];
        for (int i = 0; i < n; ++i) {
            if (sum > 0) sum += A[i];
            else sum = A[i];
            if (sum > max_sum) max_sum = sum;
        }
        return max_sum;
    }
};
