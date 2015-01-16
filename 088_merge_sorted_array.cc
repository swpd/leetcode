class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int tail = m + n - 1;
        int tailA = m - 1;
        int tailB = n - 1;
        while (tailA >= 0 && tailB >= 0) {
            if (A[tailA] > B[tailB]) {
                A[tail] = A[tailA];
                tailA--;
            } else {
                A[tail] = B[tailB];
                tailB--;
            }
            tail--;
        }
        if (tailA < 0)
            for (int i = 0; i <= tailB; ++i) A[i] = B[i];
    }
};
