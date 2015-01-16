class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int head = 0;
        int tail = n - 1;
        while (head <= tail) {
            if (A[head] == elem) {
                A[head] = A[tail];
                tail--;
            } else {
                head++;
            }
        }
        return tail + 1;
    }
};
